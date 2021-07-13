#include "globalstrikeclient.h"

GlobalStrikeClient::GlobalStrikeClient()
{
	QDateTime now;
	file.setFileName("client_log.txt");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
		qDebug() << "Logging failed.";
		return;
	}
	file.write(QString(" ----- Start of Log " + now.currentDateTime().toString() + " ----- \n").toUtf8().constData());
	file.close();
	client = new QTcpSocket;
    client->setProxy(QNetworkProxy::NoProxy); // network patch
    preReadyCountryName = QString("Atlantis");
    for(int i = 0; i < 5; i++){
        takenCountryNames.append(QString("Unset"));
        targetedBy[i] = false;
    }
    connect(client, SIGNAL(connected()), this, SLOT(handshake())); // handshakes with server
    connect(client, SIGNAL(readyRead()), this, SLOT(processPendingMessages())); // receipt from server
}

GlobalStrikeClient::~GlobalStrikeClient()
{
    if(client->state() == QAbstractSocket::ConnectedState)
        client->close();
    delete client;
}

bool GlobalStrikeClient::connectToServer(QString ipAddress, quint16 portNum)
{
	qDebug() << "Client: Attempting connection to" << ipAddress << "at port" << portNum;
	LogEvent(QString("Client: Attempting connection to " + ipAddress));
	if (client == nullptr)
    {
		qDebug() << "Client: Connection failed because client was not a valid object.";
		LogEvent(QString("Client: Connection failed because client was not a valid object."));
		return false;
	}
	client->connectToHost(ipAddress, portNum);
	client->waitForConnected();
	qDebug() << "Client: Connected to" << ipAddress << "at port" << portNum;
	LogEvent(QString("Client: Connected to " + ipAddress + "at port" + QString::number(portNum)));
	connect(client, SIGNAL(readyRead()), this, SLOT(processPendingMessages()));
	return true;
	//handshake();
}

void GlobalStrikeClient::launchCommand(QString target)
{
	QByteArray message;
	QTextStream out(&message, QIODevice::WriteOnly);
    out << "L" << endl;
    out << target << endl;
    out << playerName << endl;
    out << takenCountryNames.at(playerNames.indexOf(target)) << endl;
    out << takenCountryNames.at(playerNames.indexOf(playerName)) << endl;
    out << "Z" << endl;
	writeMessage(message);
}

void GlobalStrikeClient::interceptCommand(QString target)
{
	QByteArray message;
	QTextStream out(&message, QIODevice::WriteOnly);
    out << "I" << endl;
    out << target << endl;
    out << playerName << endl;
    out << takenCountryNames.at(playerNames.indexOf(target)) << endl;
    out << takenCountryNames.at(playerNames.indexOf(playerName)) << endl;
    out << "Z" << endl;
	writeMessage(message);
}

void GlobalStrikeClient::yieldKillPoint(QString target)
{
	QByteArray message;
	QTextStream out(&message, QIODevice::WriteOnly);
    out << "S" << endl;
    out << target << endl;
    out << playerNames.at(takenCountryNames.indexOf(target)) << endl;
    out << "Z" << endl;
	writeMessage(message);
}

void GlobalStrikeClient::readyToggle()
{
	QByteArray message;
	QTextStream out(&message, QIODevice::WriteOnly);
    out << "R" << endl;
    out << playerName << endl;
    out << preReadyCountryName << endl;
    out << "Z" << endl;
	writeMessage(message);
}

void GlobalStrikeClient::handshake() 
{
	QByteArray hand;
	QTextStream out(&hand, QIODevice::WriteOnly);
    for(int i = 0; i < 5; i++){
        takenCountryNames.append(QString("Unset"));
        targetedBy[i] = false;
    }
	out << password << endl;
	out << playerName << endl;
	LogEvent(playerName + " " + password);
	writeMessage(hand);
}

void GlobalStrikeClient::writeMessage(QByteArray message) 
{
	if (client->state() == QAbstractSocket::ConnectedState) 
    {
		client->write(message);
        client->flush();
		//LogEvent(message);
	}
}

void GlobalStrikeClient::processPendingMessages() 
{
    QString ch, temp, temp2;
	QByteArray input = client->readAll();
	LogEvent(input);
    QTextStream textData(&input, QIODevice::ReadOnly);
    while(!textData.atEnd())
    {
        textData >> ch;
        qDebug() << ch;
        switch (ch.front().toLatin1())
        {
        case 'L':
            processLaunch(textData);
            break;
        case 'I':
            processIntercept(textData);
            break;
        case 'S':
            if(hostFlag){
                emit(scoreUpdate("null"));
                break;
            }
            processScoreUpdates(textData);
            break;
        case 'R':
            if(hostFlag){
                textData >> temp;
                textData >> temp2;
                qDebug() << playerNames.indexOf(temp);
                takenCountryNames.replace(playerNames.indexOf(temp), temp2);
                emit(readyDBToggle("null", "null"));
                break;
            }
            processReadyToggleData(textData);
            break;
        case 'G':
            processGreeting(textData);
            break;
        case 'D':
            processDeny(textData);
            break;
        case 'N':
            if(hostFlag){
                textData >> temp;
                playerNames.append(temp);
                emit(newClientDB("null"));
                break;
            }
            processNewClient(textData);
            firstNewClient = false;
            // processing new connections, to extract a String and no whitespace
            // textData >> qstringVariable; reads exactly one string worth and no \n's
            break;
        case 'X':
            emit(gameIsStarting());

        case 'Z':
            qDebug() << "Client: Parsing input concluded.";
            LogEvent(QString("Client: Parsing input concluded."));
        default:
            break;
        }
    }
}

void GlobalStrikeClient::processLaunch(QTextStream& textData)
{
    QString targetCountry, originCountry;
    textData >> targetCountry;
    textData >> originCountry;
    LogEvent(QString("Client: Launched at " + targetCountry + "."));
    //whichCountry(targetCountry);
    if(takenCountryNames.at(playerNames.indexOf(playerName)) == targetCountry){
        targetedBy[takenCountryNames.indexOf(originCountry)] = true;
        whichCountry(targetCountry);
        pendingMissile missile;
        missile.originCountry = originCountry;
        missile.shotTimer = new QTimer;
        missile.shotTimer->setSingleShot(true);
        missile.shotTimer->start(3000);
        missileQueue.enqueue(missile);
    }
    // do something to start the animations
}

void GlobalStrikeClient::whichCountry(QString target){
    if(target.toUtf8().data() == "Atlantis")
        emit(animateWhite());
    else if(target.toUtf8().data() == "Cobra")
        emit(animateOrange());
    else if(target.toUtf8().data() == "Republic")
        emit(animateGreen());
    else if(target.toUtf8().data() == "West")
        emit(animateYellow());
    else if(target.toUtf8().data() == "Zathura")
        emit(animateBlack());
}

void GlobalStrikeClient::processIntercept(QTextStream& textData)
{
    QString targetCountry, originCountry;
    textData >> targetCountry;
    textData >> originCountry;
    LogEvent(QString("Client: Interceptor launched at " + targetCountry + "."));
    if(targetedBy[takenCountryNames.indexOf(targetCountry)]){
        targetedBy[takenCountryNames.indexOf(originCountry)] = false;
    }
}

void GlobalStrikeClient::processScoreUpdates(QTextStream& textData)
{
    QString pname;
    textData >> pname;
    if(!hostFlag)
        emit(scoreUpdate(pname));
}

void GlobalStrikeClient::processReadyToggleData(QTextStream& textData)
{
    QString pname;
    QString countryName;
    textData >> pname;
    textData >> countryName;
    takenCountryNames.replace(playerNames.indexOf(pname), countryName);
    if(!hostFlag)
        emit(readyDBToggle(pname, countryName));
}

void GlobalStrikeClient::processGreeting(QTextStream& textData)
{
	QString ipAddress;
	quint16 portNum;
	textData >> ipAddress;
    textData >> portNum;
    emit(lobbyIPUpdate(ipAddress, portNum));
}

void GlobalStrikeClient::processDeny(QTextStream& textData)
{
	emit(deny());
}

void GlobalStrikeClient::processNewClient(QTextStream& textData)
{
    QString pname;
    textData >> pname;
    playerNames.append(pname);
    emit(newClientDB(pname));
}

void GlobalStrikeClient::LogEvent(QByteArray data) 
{
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) 
    {
		qDebug() << "Logging failed.";
		return;
	}
	file.write(QString("|" + QString::number(lineNum++) + "| ").toUtf8().constData());
	file.write(data.replace('\n', ' '));
	file.write(QString("\n").toUtf8().constData());
	file.close();
}

void GlobalStrikeClient::LogEvent(QString data) 
{
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) 
    {
		qDebug() << "Logging failed.";
		return;
	}
	file.write(QString("|" + QString::number(lineNum++) + "| " + data + "\n").toUtf8().constData());
	file.close();
}

void GlobalStrikeClient::Dequeue(){
    pendingMissile missile = missileQueue.dequeue();
    yieldKillPoint(missile.originCountry);
}
