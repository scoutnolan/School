#ifndef GLOBALSTRIKECLIENT_H
#define GLOBALSTRIKECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkProxy>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QDateTime>
#include <QQueue>
#include "sqldatabase.h"
#include "player.h"

class GlobalStrikeClient : public QObject
{
	Q_OBJECT
public:
	GlobalStrikeClient();
	~GlobalStrikeClient();

signals:
	void deny();
	void lobbyIPUpdate(QString, quint16);
    void newClientDB(QString);
    void readyDBToggle(QString, QString);
    void scoreUpdate(QString);
    void gameIsStarting();
    void animateWhite();
    void animateOrange();
    void animateGreen();
    void animateYellow();
    void animateBlack();

public slots:
	bool connectToServer(QString ipAddress, quint16 portNum);
    void launchCommand(QString);
    void interceptCommand(QString);
    void yieldKillPoint(QString);
    void readyToggle();
	void handshake();
	void processPendingMessages();
    void Dequeue();

private:
	void writeMessage(QByteArray message);
    void processLaunch(QTextStream&);
    void processIntercept(QTextStream&);
    void processScoreUpdates(QTextStream&);
    void processReadyToggleData(QTextStream&);
    void processGreeting(QTextStream&);
    void processDeny(QTextStream&);
    void processNewClient(QTextStream&);
	void LogEvent(QByteArray);
	void LogEvent(QString);
    void whichCountry(QString);

public:
	int playerID;
	QString playerName;
	QString password;
	QTcpSocket* client;
	QFile file;
	quint16 lineNum = 1;
	quint16 portNum;
	QString ipAddress;
	QDateTime now;
    bool hostFlag = false;
    bool firstNewClient = true;
    QString preReadyCountryName;
    QList<QString> takenCountryNames;
    QList<QString> playerNames;
    bool targetedBy[5];
    struct pendingMissile{
        QString originCountry;
        QTimer* shotTimer;
    };
    QQueue<pendingMissile> missileQueue;
};

#endif // GLOBALSTRIKECLIENT_H
