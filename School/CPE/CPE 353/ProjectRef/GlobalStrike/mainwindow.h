#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QRegularExpression>
#include <QRegExpValidator>
#include <QDialog>
#include <QFile>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QObject>
#include <QDateTime>
#include <globalstrikeclient.h>
#include <globalstrikeserver.h>
#include "sqldatabase.h"
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	int time = 300;
	int Missile_cd_time = 100; // this is a percentage
	int Interceptor_cd_time = 100; // this is a percentage
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow* ui;
	Player* ThisPlayer;
	bool playersReady[5];
	QStringList playerIDList;
	QStringList playerNameList;
    SQLDatabase *d;

	QTimer* game_timer;
	QTimer* MissileTimer;
	QTimer* InterceptorTimer;

	GlobalStrikeServer* gsServer;
	GlobalStrikeClient* gsClient;

	QString pword;
	QString pname;
	QString ipAdd;
	QString pnum;

	quint16 lineNum = 1;
	QFile file;

	void LogEvent(QByteArray);
	void LogEvent(QString);

public slots:
	//void createLobby();
	//void joinLobby();
	//void LobbyFilled();
	void updateLobbyIPData(QString, quint16);
    void updatePlayerLobbyData(QString);
    void UpdateCountryName();
    void toggleReadyUpFlag(QString, QString);
    void updatePlayerScoreData(QString);
	void StartLobby();
	void JoinLobby();
	void Disconnect();
	void HomeLobby();
	void QuitWindow();
	//void GameLobby();
	void ReadyUp();
	void StartGame();
	void UpdateGameTime();
	void UpdateMissileCooldownTime();
	void UpdateInterceptorCooldownTime();
	void DisplayDb();
	void DisplayLobby();
	void EndGame();
	void LaunchMissile(QString target);
	void LaunchInterceptor(QString target);
	void LaunchConfirmMissile();
	void LaunchConfirmInterceptor();
    void AnimationGreen();
    void AnimationBlack();
    void AnimationWhite();
    void AnimationYellow();
    void AnimationOrange();
    void cleanGreen();
    void cleanWhite();
    void cleanYellow();
    void cleanOrange();
    void cleanBlack();

private slots:
	void StartServer(); // combine with StartLobby()
	void CloseServer();
	void JoinServer(); // combine with Join Lobby
};

#endif // MAINWINDOW_H
