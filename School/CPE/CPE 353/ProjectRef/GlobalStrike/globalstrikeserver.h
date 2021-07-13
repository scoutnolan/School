#ifndef GLOBALSTRIKESERVER_H
#define GLOBALSTRIKESERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QTextStream>
#include <QFile>
#include <QAbstractSocket>
#include <QDateTime>
#include <globalstrikeclient.h>
#include <QCborStreamWriter>
#include <QCborStreamReader>

class GlobalStrikeServer : public QObject
{
	Q_OBJECT
public:
	GlobalStrikeServer();
    GlobalStrikeServer(GlobalStrikeClient* client, SQLDatabase* d2);
	~GlobalStrikeServer();
    //SQL
    void processNewConnection(QString);  //QString while testing
    void setDatabase(SQLDatabase*);
signals:
	void serverReady(QString, quint16);
    //void newClientSuccess(QString); // link to adding player
public slots:
	void processMessages(QTcpSocket*);
	void processPendingConnection();
	void processDisconnectRequest();
    void debuggingReadyUp();
private:
	void startServer();
	void closeServer();
	void resetServer();
	void writeMessage(QByteArray, QTcpSocket*);
	void writeGreeting(QTcpSocket*, int);
    void writeReadyData(QTcpSocket*, QString, QString);
    void writeDeny(int, QTcpSocket*);
    void writeLaunch(QTcpSocket*, QString, QString);
    void writeIntercept(QTcpSocket*, QString, QString);
    void writeScoreBoard(QString);
    void writeNewConnection(QTcpSocket*, QString);
    void writeStartGame();
	void writeMessageToClients(QByteArray, int);
	bool processHandshake(QByteArray&, QTextStream&, QTcpSocket*);
	void processLaunchCommand(QTextStream&);
	void processInterceptCommand(QTextStream&);
	void processYieldedKillPoint(QTextStream&);
	void processReadyToggleCommand(QTextStream&);
    // // ?

	void LogEvent(QByteArray);
	void LogEvent(QString);

	//SERVER DATA
	QTcpServer* server;
	GlobalStrikeClient* hostClient;
	// need a player struct
	QString ipAddress;
	quint16 portNum;
	QString password;
	qint64 pLength;
	QList<QString> playerNames;
	QFile file;
	quint16 lineNum = 1;
	QDateTime now;
	QList<QTcpSocket*> playerSockets;
    bool closingServer = false;
    QList<bool> readyStatusFlags;
    QList<QString> countrySelections;
	// PLAYER DATA
    //SQL
    SQLDatabase* d;

};

#endif // GLOBALSTRIKESERVER_H
