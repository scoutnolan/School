#include "global.h"
#include "ui_hwindow.h"
#include "message.h"

extern unsigned short HOST_PORT;
extern int PlayerCount;
extern int myID;
extern QString MyUserName;


// ***** Starting the server ***** //

Stick::Hwindow::Hwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hwindow)
{
    ui->setupUi(this);
    connect(this, &Hwindow::newMessage, this, &Hwindow::displayMessage);            // Implementation for message receive, but for usernames.
    connect(ui->HButtonH, SIGNAL(clicked()), this, SLOT(HostGame()));               // If the Host button is clicked, call the HostGame function.
    connect(ui->BButtonH, SIGNAL(clicked()), this, SLOT(on_BButtonH_clicked()));    // If the Back button is clicked, close the game.
    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(StartStickBattle()));    // Start Button
    connect(ui->LButton, SIGNAL(clicked()), this, SLOT(OpenLWindow()));             // Leaderboard button
    connect(ui->SendMessageButton, SIGNAL(clicked()), this, SLOT(SendMessage()));   // Send a message from the host.
    connect(ui->settingsPushButton, SIGNAL(clicked()), this, SLOT(OpenSWindow()));  // Connect statement to open the settings window.
    connect(ui->PlayerNumH, SIGNAL(textChanged(const QString&)), this, SLOT(updateNum()));


    // ***** Username and player count ***** //
    QRegularExpression usernameRegExp("[a-zA-Z]{5}");                               // Limits the username to 5 characers
    ui->UserEditH->setValidator(new QRegularExpressionValidator(usernameRegExp));   // Sets the validator to the user edit line text.
    ui->PlayerNumH->setValidator(new QIntValidator(1, 5, this));                    // only allows user to input numbers from 1-5
    QString* NumPlayers = new QString;                                              // New int object for input.
    *NumPlayers = ui->PlayerNumH->text();                                           // Lets the host edit number of players.
    PlayerCount = ui->PlayerNumH->text().toInt();                                   // Setting the number of players (for lobbywindow.h/.cpp)
}

// ***** Host game when button is clicked ***** //
void Stick::Hwindow::HostGame()
{
    // Does not allow user to start game w/o entering username.
    if(ui->UserEditH->text().isEmpty())
    {
        return;
    }
    // Starting the server //
    server = new QTcpServer();
    if(server->listen(QHostAddress::Any, HOST_PORT))
    {
       connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
       qDebug() << "Server started on" << QHostAddress::Any << ":" << HOST_PORT;
    }
    else
    {
        qDebug() << "Unable to start the server:" << server->errorString();
        exit(EXIT_FAILURE);
    }
    MyUserName = ui->UserEditH->text();
}

void Stick::Hwindow::onNewConnection()
{
    while (server->hasPendingConnections())
        appendToSocketList(server->nextPendingConnection());
}

void Stick::Hwindow::displayMessage(const QString& str)
{

}

void Stick::Hwindow::appendToSocketList(QTcpSocket* newsocket)
{
    connection_list.append(newsocket);
    connect(newsocket, &QTcpSocket::readyRead, this, &Hwindow::readSocket);

    Player* newplayer = new Player();            // new player object.
    myID++;
    if (myID==1) {
            newplayer->SetAll(myID, ui->UserEditH->text(), Qt::red);
            QByteArray out;
            QTextStream outData(&out, QIODevice::WriteOnly);
            outData << static_cast<int>(Message::SetId) << endl << myID << endl;
            if(newsocket->state() == QAbstractSocket::ConnectedState){
                newsocket->write(out);
                newsocket->flush();
            }
    }
    else if (myID==2) {
            newplayer->SetAll(myID, ui->UserEditH->text(), Qt::green);
            QByteArray out;
            QTextStream outData(&out, QIODevice::WriteOnly);
            outData << static_cast<int>(Message::SetId) << endl << myID << endl;
            if(newsocket->state() == QAbstractSocket::ConnectedState){
                newsocket->write(out);
                newsocket->flush();
            }
    }
    else if (myID==3) {
            newplayer->SetAll(myID, ui->UserEditH->text(), Qt::yellow);
            QByteArray out;
            QTextStream outData(&out, QIODevice::WriteOnly);
            outData << static_cast<int>(Message::SetId) << endl << myID << endl;
            if(newsocket->state() == QAbstractSocket::ConnectedState){
                newsocket->write(out);
                newsocket->flush();
            }
    }
    else if (myID==4) {
            newplayer->SetAll(myID, ui->UserEditH->text(), Qt::magenta);
            QByteArray out;
            QTextStream outData(&out, QIODevice::WriteOnly);
            outData << static_cast<int>(Message::SetId) << endl << myID << endl;
            if(newsocket->state() == QAbstractSocket::ConnectedState){
                newsocket->write(out);
                newsocket->flush();
            }
    }
}

void Stick::Hwindow::readSocket()
{
    Stick::gamewindow game;
    gamewindow mygamewindow;
    int dataType;
    QTcpSocket* insocket = reinterpret_cast<QTcpSocket*>(sender());
    QByteArray in= insocket->readAll();
    QTextStream inData(&in, QIODevice::ReadOnly);
    inData >> dataType;
    switch (dataType)   // case statements need to be implemented with functions
                        // that take inData with them. Message::Message is an outlier
    {
        // Client to Server
        case static_cast<int>(Message::StartGame):
            break;
        case static_cast<int>(Message::Moved):
            break;
        case static_cast<int>(Message::Dodge):
            break;
        case static_cast<int>(Message::Tag):
            break;
        case static_cast<int>(Message::Die):
        mygamewindow.updateScoreHost(inData);
            break;
        case static_cast<int>(Message::Respawn):
            break;
        case static_cast<int>(Message::ExitGame):
            break;
        case static_cast<int>(Message::PlayerTag):
            break;



        // Server to Client
        case static_cast<int>(Message::Error):
            break;
        case static_cast<int>(Message::PlayerColor):
            break;
        case static_cast<int>(Message::UpdatePlayerPos):
            break;
        case static_cast<int>(Message::TagPressed):
            break;
        case static_cast<int>(Message::UpdateLeaderboard):
            break;
        case static_cast<int>(Message::SendToLeaderboard):
            break;
        case static_cast<int>(Message::LoadGame):
            break;
        case static_cast<int>(Message::UpdatePlayerName):
            break;
        case static_cast<int>(Message::SetId):
            break;
        case static_cast<int>(Message::RemoveObject):
            break;
        case static_cast<int>(Message::AddObject):
            break;
        case static_cast<int>(Message::GameStart):
            break;

        //Lobby Chat
        case static_cast<int>(Message::Message):
            QString str1, str2, str3, str;
            inData >> str1;
            inData >> str2;
            while (!inData.atEnd()) {   //goes through inData to grab all str words
                inData>> str3;
                str2= str2+" "+str3;
            }
            str= str1 + " " +str2;
            ui->textBrowser->append(str);

            //echoes client messages back to all clients
            QByteArray out;
            QTextStream outData(&out, QIODevice::WriteOnly);
            outData << static_cast<int>(Message::Message) << endl << str << endl;
            QList<QTcpSocket*>::iterator it;

            for (it=connection_list.begin(); it!=connection_list.end(); it++) {
                //qDebug() <<(*it);
                if((*it)->state() ==  QAbstractSocket::ConnectedState) {
                    (*it)->write(out);
                    (*it)->flush();
                }
            }
            break;
    }
}

void Stick::Hwindow::sendtoClients(QByteArray& out)
{
    QList<QTcpSocket*>::iterator it;
    for (it=connection_list.begin(); it!=connection_list.end(); it++) {
        //qDebug() <<(*it);
        if((*it)->state() ==  QAbstractSocket::ConnectedState) {
            (*it)->write(out);
            (*it)->flush();
        }
    }
}

void Stick::Hwindow::SendMessage()
{
    QString username = ui->UserEditH->text();
    QString words= ui->SendMessageEdit->text();
    QString str= username + ": ";
    QByteArray out;
    QTextStream outData(&out, QIODevice::WriteOnly);
    outData << static_cast<int>(Message::Message) << endl << str << endl << words << endl;
    QList<QTcpSocket*>::iterator it;
    for (it=connection_list.begin(); it!=connection_list.end(); it++)
    {
        if((*it)->state() ==  QAbstractSocket::ConnectedState)
        {
            (*it)->write(out);
            (*it)->flush();
        }
    }
    ui->textBrowser->append(str+words);
    ui->SendMessageEdit->clear();
}

// ***** Edit the port number ***** //
void Stick::Hwindow::on_PortEditH_textEdited(const QString &arg1)
{
    QRegularExpression PortRegExp("[0-9]{4}");                                  // Limits the name input to 0-9 and 4 characters long
    ui->PortEditH->setValidator(new QRegularExpressionValidator(PortRegExp));   // Sets the validator
    HOST_PORT =ui->PortEditH->text().toInt();                                   // Host port set.
}

// ***** Add username to the database ***** //
void Stick::Hwindow::on_HButtonH_clicked()
{
    if(ui->UserEditH->text().isEmpty())
    {
        return;
    }
    Stick::Usernames Object;
    QSqlQuery *query = new QSqlQuery(Object.db);            // Create a query based on the database name.
    Object.db.open();                                       // Open the database.
    QString hostname = "Host: " + ui->UserEditH->text() + " started a new game.";   // Hostname qstring.
    ui->textBrowser->append(hostname);                                              // Shows the hosts username.
    Player* host = new Player();                        // new player object.
    host->SetAll(0, ui->UserEditH->text(), Qt::blue);   // Sets the initial variables
}

// Start the game
void Stick::Hwindow::StartStickBattle()
{
    myID=0;
    MyGWindow = new gamewindow();       // New game window object
    MyGWindow -> showFullScreen();      // Show the game window.
    QByteArray startgame;
    QTextStream requestMessage(&startgame, QIODevice::WriteOnly);
    requestMessage << static_cast<int>(Message::GameStart) << endl << PlayerCount << endl;
    QList<QTcpSocket*>::iterator it;
    for (it=connection_list.begin(); it!=connection_list.end(); it++) {
        if((*it)->state() ==  QAbstractSocket::ConnectedState) {
            (*it)->write(startgame);
            (*it)->flush();
        }
    }
}

// Open leaderboard window
void Stick::Hwindow::OpenLWindow()
{
    MyLWindow = new Lwindow();          // Show leaderboard menu.
    MyLWindow -> show();
}

void Stick::Hwindow::OpenSWindow()
{
    MySWindow = new Swindow();          // Open Settings menu.
    MySWindow -> show();
    connect(MySWindow, SIGNAL(colorChosen()), this, SLOT(colorSelect()));
}

// ***** Back Button ***** //
void Stick::Hwindow::on_BButtonH_clicked()
{
    this->close();
}

Stick::Hwindow::~Hwindow()
{
    delete ui;
}

void Stick::Hwindow::colorSelect()
{
    Player* color = new Player();
    color[0].color = MySWindow->colorFind();
    this->color = MySWindow->colorFind();               // Sets the color.
}

void Stick::Hwindow::updateNum()
{
    QString* NumPlayers = new QString;
    *NumPlayers = ui->PlayerNumH->text();
    PlayerCount = NumPlayers->toInt();
}





