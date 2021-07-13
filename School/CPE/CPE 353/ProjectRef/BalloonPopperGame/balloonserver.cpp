#include "balloonserver.h"
#include "ui_server.h"
#include <QString>
#include <QNetworkInterface>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QRandomGenerator>
#include <QtMath>
#include <QNetworkProxy>
#include "messagetype.h"
#include "defs.h"

//constructor, inherits from QDialog
BalloonServer::BalloonServer(QWidget *parent)
    : QDialog(parent)
    //, ui(new Ui::BalloonServer)
{
    //ui->setupUi(this);
    tcpServer = new QTcpServer(this); //initialize tcp server
    lobby = new Lobby; // Create lobby
    StartServer();
    connect(tcpServer, &QTcpServer::newConnection, this, &BalloonServer::SendHelloMessage); //when a new connection is made to a client, say hi!
//    connect(ui->closeButton, &QPushButton::clicked, [=]{
//        emit closeClicked();
//    });

    //Lobby connections
    connect(lobby, &Lobby::UpdateLobby, this, &BalloonServer::SendPlayerData);
    connect(lobby,&Lobby::removeID, [=](qint16 i){
        activeIDs.removeAll(i); // This most likely doesn't work when players dc and rejoin
        qDebug() << "Removing id: " << i;
    });
    // Set up available color list
    availableColors.append(static_cast<int>(Color::Red));
    availableColors.append(static_cast<int>(Color::Pink));
    availableColors.append(static_cast<int>(Color::Cyan));
    availableColors.append(static_cast<int>(Color::Yellow));
    availableColors.append(static_cast<int>(Color::Green));
    availableColors.append(static_cast<int>(Color::Blue));
    availableColors.append(static_cast<int>(Color::Purple));
    availableColors.append(static_cast<int>(Color::Black));
}

void BalloonServer::closeServer(){
    lobby->disconnectAllClients();
    this->close();
}

void BalloonServer::playerDataReset(){
    Player* player = nullptr;
    for(auto i : activeIDs){
        if(lobby->getPlayer(i,player)){
            player->posX = 0;
            player->score = 0;
        }
    }
}

//destructor
BalloonServer::~BalloonServer()
{
    //delete ui;
    delete lobby;
}

//slot function to start server once user clicks start button
void BalloonServer::StartServer()
{
    //qDebug() << "we are trying to start a server.";

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use  the first non-localhost IPv4 address
    //I THINK that this code just finds the address that the host is using
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())    //if we never put anything into it
    {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }

    // By moving this past the for loop we set a single IP address dynamically
    if(!tcpServer->listen(QHostAddress(ipAddress)/*/QHostAddress::LocalHost*/))
    {
        //qDebug() << "it ain't workin";
        close(); //if it fails, we exit
        return;
    }

    //ui->addressLabel->setText(ipAddress); //display which ip address client's should access
    //ui->portLabel->setText(tr("%1").arg(tcpServer->serverPort()));  //display the port in use

    //qDebug()<< tcpServer->serverAddress();
    //qDebug() << tcpServer->serverPort();

    //qDebug() <<"it should have worked ?";

    return;
}

// Send updated lobby/name data to all clients
void BalloonServer::SendPlayerData(){
    QByteArray out;
    QTextStream outgoingData(&out, QIODevice::WriteOnly);
    UpdateColorList();
    outgoingData << static_cast<int>(MessageType::UpdatePlayerName) << endl << lobby->getLobbySize() << endl;
    // Set up client names
    Player* player = nullptr;
    for(auto i : activeIDs){ //Loop through current ID list to set up name list
        if(lobby->getPlayer(i,player)){
            //qDebug() << "Player is added to message list: " << player->name << player->id;
            outgoingData << player->name << endl // send name
                         << player->id << endl // send id
                         << player->color << endl   // send color
                         << player->score << endl;  // send score
                        // Should we send player coords as well?
        }
    }
    lobby->sendMessageToClients(out); // Send message to all clients
}

void BalloonServer::sendPlayerPosData(){
    QByteArray out;
    QTextStream outgoingData(&out, QIODevice::WriteOnly);
    outgoingData << static_cast<int>(MessageType::PlayerPosChange) << endl << lobby->getLobbySize() << endl;
    // Set up client names
    Player* player = nullptr;
    for(auto i : activeIDs){ //Loop through current ID list to set up name list
        if(lobby->getPlayer(i,player)){
            outgoingData << player->id << endl // send id
                         << player->posX << endl; // send known pos
        }
    }
    lobby->sendMessageToClients(out); // Send message to all clients
}

void BalloonServer::SendPlayerScoreData()
{
    QByteArray out;
    QTextStream outgoingData(&out, QIODevice::WriteOnly);
    outgoingData << static_cast<int>(MessageType::UpdatePlayerScores) << endl << lobby->getLobbySize() << endl;
    // Set up client names
    Player* player = nullptr;
    for(auto i : activeIDs)         //Loop through current ID list to set up name list
    {
        if(lobby->getPlayer(i, player))
        {
            outgoingData << player->name << endl    // send name
                         << player->score << endl;  // send score
        }
    }
    lobby->sendMessageToClients(out);               // Send message to all clients
}

void BalloonServer::SendFinalScoreData(QTextStream& incomingData)
{
    qint16 specificID;
    incomingData >> specificID;
    QByteArray out;
    QTextStream outgoingData(&out, QIODevice::WriteOnly);
    outgoingData << static_cast<int>(MessageType::SendFinalScores) << endl << lobby->getLobbySize() << endl;
    // Set up client names
    Player* player = nullptr;
    for(auto i : activeIDs)         //Loop through current ID list to set up name list
    {
        if(lobby->getPlayer(i, player))
        {
            outgoingData << player->name << endl    // send name
                         << player->score << endl;  // send score
        }
    }
    lobby->sendMessageToSpecificClient(specificID, out);    // Send message to one client
}

//void BalloonServer::SendHScoreData(QTcpSocket *socket)
//{
//    QByteArray out;
//    QTextStream outgoingData(&out, QIODevice::WriteOnly);
//    outgoingData << static_cast<int>(MessageType::HighScoreList) << endl;

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("lobbyScores.db");
//    if(!db.open())
//    {
//        qDebug() << db.lastError();
//        qDebug() << "Error: unable to connect to database";
//        return;
//    }

//    QSqlQuery q("DROP TABLE lobbyscores");
//    q.prepare("CREATE TABLE lobbyscores(name TEXT, score INT)");
//    if(!q.exec())
//    {
//        qDebug() << db.lastError();
//        qDebug() << "Error: database error";
//        return;
//    }

//    Player* player = nullptr;
//    for(auto i : activeIDs)         //Loop through current ID list to set up name list
//    {
//        if(lobby->getPlayer(i, player))
//        {
//            q.prepare("INSERT INTO scores VALUES(:rank, :name, :score)");
//            q.bindValue(":rank", i+1);
//            q.bindValue(":name", plarray[i].name);
//            q.bindValue(":score", plarray[i].score);
//            if(!q.exec())
//            {
//                db.lastError();
//                qDebug() << "Error adding values";
//            }
//        }
//    }

//    while(q.next())
//    {
//        outgoingData << q.value(0).toString() << endl <<
//                        q.value(1).toString() << endl <<
//                        q.value(2).toString() << endl;
//    }
//    socket->write(out);
//    socket->flush();
//}

// Set up client connection. Get clients name. Update lobby
void BalloonServer::SendHelloMessage()
{
    QTcpSocket* tmpSocket = tcpServer->nextPendingConnection(); // grab socket trying to connect

    qDebug()<< tmpSocket->errorString();        // NETWORKING PATCH FOR LAB
    tmpSocket->setProxy(QNetworkProxy::NoProxy);

    // The following could be done differently with a different AddPlayer method
    tmpSocket->waitForReadyRead(1000); // wait 1000ms max
    QString playerName;
    QByteArray in = tmpSocket->readAll();   //place the client's latest messagein a byte array
    QTextStream incomingData(&in, QIODevice::ReadOnly); //connect to a text stream
    incomingData >> playerName;          //grab player name to add player

    if(lobby->AddPlayer(tmpSocket, playerName, availableColors.takeFirst())){ // if successful set up connections
        connect(tmpSocket, &QTcpSocket::readyRead, [=]{
            DataReceival(tmpSocket);
        });
        connect(tmpSocket, &QTcpSocket::disconnected, lobby, &Lobby::DisconnectHandler);
        connect(tmpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
                [=](QAbstractSocket::SocketError socketError){
            qDebug() << socketError;
        });

        // Set up clients ID
        activeIDs.append(lobby->getNextID()-1);
        QByteArray out;
        QTextStream idSend(&out, QIODevice::WriteOnly);
        idSend << static_cast<int>(MessageType::SetId) << endl << lobby->getNextID()-1 << endl;
        // Only the current client will receive this message
        tmpSocket->write(out);
        tmpSocket->flush();
        SendPlayerData();
    }
    else {
        QByteArray deny;
        QTextStream denialStream(&deny,  QIODevice::WriteOnly);
        denialStream << static_cast<int>(MessageType::UpdatePlayerName) << endl << 15 << endl;
        tmpSocket->write(deny);
        tmpSocket->flush();
        tmpSocket->disconnectFromHost();
        tmpSocket->deleteLater();
    }
}

/*******************************************
 *              Data Receival
 * For any function that processes data
 * You must first pass the incomingData
 * stream.
 * i.e. myProcessDataFunction(incomingData)
 * *****************************************/

// This will be the new data receival function once the lobby class is ready
void BalloonServer::DataReceival(QTcpSocket *socket)
{
    //qDebug() << "server receiving data of some sort!";
    QByteArray in = socket->readAll();
    QTextStream incomingData(&in, QIODevice::ReadOnly);
    incomingData >> dataOption;
    switch(dataOption)
    {
    case static_cast<int>(MessageType::StartGameRequest):
        StartGame(incomingData);
        break;
    case static_cast<int>(MessageType::ColorChangeRequest):
        ColorChangeRequest(incomingData);
        break;
    case static_cast<int>(MessageType::ShootPellet):
        //qDebug() << "received pellet request (server-side)";
        pelletAdded(incomingData);
        break;
    case static_cast<int>(MessageType::MovedLeft):
        playerMovedLeft(incomingData);
        break;
    case static_cast<int>(MessageType::MovedRight):
        playerMovedLeft(incomingData);
        break;
    case static_cast<int>(MessageType::IncPlayerScore):
        IncScore(incomingData);
        break;
    case static_cast<int>(MessageType::SendFinalScores):
        SendFinalScoreData(incomingData);
        break;
    default:
        qDebug() << "Server side No case statement set up";
        break;
    }
}

void BalloonServer::pelletAdded(QTextStream& incomingData){
    qint16 ID;
    QString color = "0";
    int pos;
    incomingData >> ID >> pos; // get player ID and pos

    //Now formulate reply
    QByteArray out;
    QTextStream reply(&out, QIODevice::WriteOnly);

    // We are only going to send the color for the return
    Player* player = nullptr;
    if(lobby->getPlayer(ID, player)){
        switch(player->color){
            case static_cast<int>(Color::Red):
                color = "Red";
                break;
            case static_cast<int>(Color::Pink):
                color = "Pink";
                break;
            case static_cast<int>(Color::Cyan):
                color = "Cyan";
                break;
            case static_cast<int>(Color::Yellow):
                color = "Yellow";
                break;
            case static_cast<int>(Color::Green):
                color = "Green";
                break;
            case static_cast<int>(Color::Blue):
                color = "Blue";
                break;
            case static_cast<int>(Color::Purple):
                color = "Purple";
                break;
            case static_cast<int>(Color::Black):
                color = "Black";
                break;
        }
    }

    reply << static_cast<int>(MessageType::PelletAdded) << endl
          << ID << endl // may not need if not just empty read it
          << color << endl // will be used for color of pellet
          << pos << endl; // position to spawn in
    lobby->sendMessageToClients(out); // send to all clients
}

void BalloonServer::playerMovedLeft(QTextStream &incomingData){
    qint16 ID;
    qreal pos = 0;
    incomingData >> ID >> pos; // get player ID and pos

    // Set new player coords
    Player* player = nullptr;
    if(lobby->getPlayer(ID, player)){
        player->posX = pos; // update player pos
    }
    sendPlayerPosData();
}

void BalloonServer::StartGame(QTextStream &incomingData){
    // Grab host set time
    int time;
    incomingData >> time;

    // Create message
    QByteArray out;
    QTextStream outgoingRequest(&out, QIODevice::WriteOnly);
    outgoingRequest << static_cast<int>(MessageType::LoadGame) << endl
                    << time << endl;
    int skip = 0;
    // Send to all except host
    for(auto i : activeIDs){
        if(skip != 0){ // skip first player(should be host)
            //qDebug() << "Server registered host games start button press";
            lobby->sendMessageToSpecificClient(i,out);
        }
        else skip++;
    }
    CreateAndSendSchedule(time); //(not yet ready)
}

void BalloonServer::ColorChangeRequest(QTextStream &incomingData){
    int color;
    qint16 id;
    incomingData >> id;
    incomingData >> color;

    // Check if color is available and if so update player data
    if(availableColors.removeOne(color)){
        Player* player;
        if(lobby->getPlayer(id,player)){
            player->color = color;
           // qDebug() << "server recieved color: " << color
            //         << "client color: " << player->color;
        }
    }
    SendPlayerData();
}

void BalloonServer::UpdateColorList(){
    QList<int> colors;
    // Add all colors then remove any that overlap
    colors.append(static_cast<int>(Color::Red));
    colors.append(static_cast<int>(Color::Pink));
    colors.append(static_cast<int>(Color::Cyan));
    colors.append(static_cast<int>(Color::Yellow));
    colors.append(static_cast<int>(Color::Green));
    colors.append(static_cast<int>(Color::Blue));
    colors.append(static_cast<int>(Color::Purple));
    colors.append(static_cast<int>(Color::Black));

    // Remove all unavailable colors
    Player* player;
    for(auto i : activeIDs){
        if(lobby->getPlayer(i,player)){
            colors.removeAll(player->color);
        }
    }
    // clear previous list and set it equal to the new list
    availableColors.clear();
    availableColors = colors;
}

void BalloonServer::CreateAndSendSchedule(int timelimit){
    int v, w, c, d;
    QList<int> Times;
    QList<int> BalloonID;
    QList<int> BalloonColors;
    QList<int> XCoordinates;
    QList<int> YCoordinates;
    QList<int> Trajectories;

    qDebug() << "Preparing to Create Schedule";

    // Randomly populate Times QList based off of selected time limit
    for (int i = timelimit; i > 0; i--) {
        v = QRandomGenerator::global()->bounded(5, 10);
        for (int j = v; j > 0; j--) {
            w = QRandomGenerator::global()->bounded(((j-1)*1000)/v, ((j*1000)/v)-1);
            Times.append((i*1000) + w);
        }
    }

    // Populate BalloonID with unique ID value for each Balloon
    c = Times.count();
    for (int i = 0; i < c; i++) {
        BalloonID.append(i);
    }

    // Populate BalloonColors with a relatively equal number of all colors
    c = Times.count();
    d = floor(c/8);
    for(int i = 0; i < d; i++) {
        BalloonColors.append(static_cast<int>(Color::Red));
        BalloonColors.append(static_cast<int>(Color::Pink));
        BalloonColors.append(static_cast<int>(Color::Cyan));
        BalloonColors.append(static_cast<int>(Color::Yellow));
        BalloonColors.append(static_cast<int>(Color::Green));
        BalloonColors.append(static_cast<int>(Color::Blue));
        BalloonColors.append(static_cast<int>(Color::Purple));
        BalloonColors.append(static_cast<int>(Color::Black));
    }
    if((d*8) != c) {
        for (int i = 0; i < (c-(d*8)); i++) {
            v = QRandomGenerator::global()->bounded(7);
            if(v == 0) {BalloonColors.append(static_cast<int>(Color::Red));}
            else if(v == 1) {BalloonColors.append(static_cast<int>(Color::Pink));}
            else if(v == 2) {BalloonColors.append(static_cast<int>(Color::Cyan));}
            else if(v == 3) {BalloonColors.append(static_cast<int>(Color::Yellow));}
            else if(v == 4) {BalloonColors.append(static_cast<int>(Color::Green));}
            else if(v == 5) {BalloonColors.append(static_cast<int>(Color::Blue));}
            else if(v == 6) {BalloonColors.append(static_cast<int>(Color::Purple));}
            else {BalloonColors.append(static_cast<int>(Color::Black));}
        }
    }

    // Populate XCoordinates with random x coordinates to spawn balloons at
    for (int i = 0; i < c; i++) {
        v = QRandomGenerator::global()->bounded(640);
        XCoordinates.append(v);
    }

    // Populate YCoordinates with random y coordinates to spawn balloons at
    for (int i = 0; i < c; i++) {
        v = QRandomGenerator::global()->bounded(-YMAX+60, -YMAX+110);
        YCoordinates.append(v);
    }

    // Populate Trajectories with random trajectories based on associate x coordinate
    for (int i = 0; i < c; i++) {
        if(XCoordinates[i] < 160) {
            v = QRandomGenerator::global()->bounded(70, 90);
            Trajectories.append(v);
        }
        else if (XCoordinates[i] >= 160 && XCoordinates[i] < 480) {
            v = QRandomGenerator::global()->bounded(70, 110);
            Trajectories.append(v);
        }
        else {
            v = QRandomGenerator::global()->bounded(90, 110);
            Trajectories.append(v);
        }
    }
    if(c>BalloonColors.count()) c = BalloonColors.count();
    if(c>XCoordinates.count()) c = XCoordinates.count();

    qDebug() << "Schedule Created";

    // Send Schedule to Clients
    QByteArray Schedule;
    QTextStream outgoingData(&Schedule, QIODevice::WriteOnly);
    outgoingData << static_cast<int>(MessageType::BalloonSchedule) << endl << Times.count() << endl;
    for (int i = 0; i < c; i++) {
        outgoingData << Times[i] << endl // send spawn time
                     << BalloonID[i] << endl // send Balloon ID
                     << BalloonColors[i] << endl // send color
                     << XCoordinates[i] << endl // send spawn coordinate
                     << YCoordinates[i] << endl // send y coordinate for spawn
                     << Trajectories[i] << endl; // send trajectory
    }
    lobby->sendMessageToClients(Schedule);

    // Send info
    //QByteArray sendList;
    //QTextStream out(&sendList, QIODevice::WriteOnly);
    // set up message type and each list size
    //out << static_cast<int>(MessageType::BalloonAdded) << endl << Times.size()
    //    << endl << BalloonColors.size() << endl << XCoordinates.size() << endl;
    //for(int i : Times)
}

void BalloonServer::IncScore(QTextStream &incomingData)
{
    qint16 ID;
    int score;
    incomingData >> ID >> score; // get player ID and pos

    // Set new player coords
    Player* player;
    if(lobby->getPlayer(ID, player))
    {
        player->score = score; // update player score
    }
    SendPlayerScoreData();
}

//void BalloonServer::UpdateHScoreData(QTextStream &incomingData)
//{
    /* code */
//}
