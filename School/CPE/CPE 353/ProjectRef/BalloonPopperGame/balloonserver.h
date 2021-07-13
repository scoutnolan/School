#ifndef BALLOONSERVER_H
#define BALLOONSERVER_H

#include <QDialog>
#include <QtNetwork/QTcpServer>
#include <QLabel>
#include <messagetype.h>
#include <QList>
#include "lobby.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


//QT_BEGIN_NAMESPACE
//namespace Ui { class BalloonServer; }
//QT_END_NAMESPACE

struct clientInfo{

    // Socket for connection
    QTcpSocket *socket;

    // Add qint8/qint16 variables for positions
    qint16 posX = 0;
    qint16 posY = 0;
    int color = static_cast<int>(Color::NullColor);
    int score = 0;

    //Client Name
    QString playerName = "unknown";

    //Index data **might be useful for handling disconnects (working to replace this with linked list iterator)
    quint8 m_index = 0;
};


class BalloonServer : public QDialog
{
    Q_OBJECT

public:
    explicit BalloonServer(QWidget *parent = nullptr); //I'm not sure why these constructors are usually explicit
    ~BalloonServer();
    QHostAddress getIP() const{return tcpServer->serverAddress();}
    quint16 getPort() const{return tcpServer->serverPort();}
signals:
    void closeClicked();

public slots:
    void closeServer();
    void playerDataReset(); // Resets positional and score data

private:
    //Ui::BalloonServer *ui;

    // Private Data
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //db uses sqlite structurew
    QTcpServer *tcpServer = nullptr; //declare our server object
    Lobby *lobby = nullptr;         //Will replace current list structure when it is complete
    QList<clientInfo*> clientList;  // Declare client list
    QList<quint8> openLobbySpot;
    quint8 lobbySize = 0;
    int dataOption = 0; // Used to read in type of message to be sent
    int colorRequested = static_cast<int>(Color::NullColor);
    QList<int> availableColors; // Used to store unchosen colors
    QList<int> unavaialableColors;
    QList<qint16> activeIDs;


    // Other Functions
    void UpdateColorList();
    void CreateAndSendSchedule(int timelimit);
    void UpdateHighScoreDatabase(); // called when a game ends. Adds the highest score to the db.

    // Send Functions
    void SendPlayerData();
    void SendHighScore();
    void SendPlayerPosition();
    void SendProjectileCreateRequest();
    void sendPlayerPosData();
    void SendPlayerScoreData();
    void SendFinalScoreData(QTextStream&);

    // RECEIVAL FUNCTIONS
    void StartGame(QTextStream &incomingData);
    void ColorChangeRequest(QTextStream &incomingData);
    void UpdateHScoreData(QTextStream &incomingData);
    void pelletAdded(QTextStream&);
    void playerMovedLeft(QTextStream&);
    void playerMovedRight(QTextStream&);
    void IncScore(QTextStream&);

private slots:
    void StartServer();
    void SendHelloMessage();
    void DataReceival(QTcpSocket*);


};
#endif // BALLOONSERVER_H
