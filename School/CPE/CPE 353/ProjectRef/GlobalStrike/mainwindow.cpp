#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quit.h"
#include "sqldatabase.cpp"
#include "countryselection.h"
#include <QMovie>
#include <QBitmap>
#include <QTimer>


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	QDateTime now;
	file.setFileName("mainWindow_log.txt");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
    {
		qDebug() << "logging failed.";
		return;
	}
	file.write(QString(" ----- Start of Log " + now.currentDateTime().toString() + " ----- \n").toUtf8().constData());
	file.close();
    gsClient = new GlobalStrikeClient;
    gsServer = nullptr;
    d = new SQLDatabase;

	ui->setupUi(this);
	ui->tabWidget->setCurrentIndex(0);

	// CHANGE VIEW SIGNALS AND SLOTS
	connect(ui->StartLobbyButton, SIGNAL(clicked()), this, SLOT(StartLobby()));
	connect(ui->JoinLobbyButton, SIGNAL(clicked()), this, SLOT(JoinLobby()));
	connect(ui->homebutton1, SIGNAL(clicked()), this, SLOT(HomeLobby()));
	connect(ui->homebutton2, SIGNAL(clicked()), this, SLOT(HomeLobby()));
	connect(ui->leaveButton, SIGNAL(clicked()), this, SLOT(HomeLobby()));
	connect(ui->leaveButton2, SIGNAL(clicked()), this, SLOT(HomeLobby()));
	connect(ui->quitButtonGameLobby, SIGNAL(clicked()), this, SLOT(HomeLobby()));
	connect(ui->quitButtonGameLobby_2, SIGNAL(clicked()), this, SLOT(HomeLobby()));

    // SERVER/CLIENT MAIN WINDOW ONLY BASED SIGNALS AND SLOTS
	connect(ui->startServerButton, SIGNAL(clicked()), this, SLOT(StartServer()));
	connect(ui->closeServerButton, SIGNAL(clicked()), this, SLOT(CloseServer()));
	connect(ui->JoinButton, SIGNAL(clicked()), this, SLOT(JoinServer()));
	connect(ui->readyButton, SIGNAL(clicked()), this, SLOT(ReadyUp()));
	connect(gsClient, SIGNAL(lobbyIPUpdate(QString, quint16)), this, SLOT(updateLobbyIPData(QString, quint16)));
    connect(gsClient, SIGNAL(gameIsStarting()), this, SLOT(StartGame()));

	// GAME BASED SIGNALS AND SLOTS
	//Connection for "Launch Missile" gameplay button to corresponding function
    connect(ui->LaunchMissile, SIGNAL(clicked()), this, SLOT(LaunchConfirmMissile()));
	//Connection for "Launch Interceptor" gameplay button to corresponding function
	connect(ui->LaunchInterceptor, SIGNAL(clicked()), this, SLOT(LaunchConfirmInterceptor()));

    // CLIENT/DATABASE SIGNALS AND SLOTS
    connect(gsClient, SIGNAL(newClientDB(QString)), this, SLOT(updatePlayerLobbyData(QString)));
    connect(gsClient, SIGNAL(readyDBToggle(QString, QString)), this, SLOT(toggleReadyUpFlag(QString, QString)));
    connect(gsClient, SIGNAL(scoreUpdate(QString)), this, SLOT(updatePlayerScoreData(QString)));

	// QUIT BASED SIGNALS AND SLOTS
	connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(QuitWindow()));
	connect(ui->quitButton2, SIGNAL(clicked()), this, SLOT(QuitWindow()));
	connect(ui->quitButton3, SIGNAL(clicked()), this, SLOT(QuitWindow()));
	connect(ui->quitButton4, SIGNAL(clicked()), this, SLOT(QuitWindow()));
	connect(ui->quitButton5, SIGNAL(clicked()), this, SLOT(QuitWindow()));

    ui->countryButton->setText("Atlantis");
    connect(ui->countryButton, SIGNAL(clicked()), this, SLOT(UpdateCountryName()));
	// ui->lineEdit_4->setText("");
	// ui->lineEdit->setReadOnly(true);
	// ui->lineEdit_4->setText("0/5");
	// ui->lineEdit_4->setReadOnly(true);
	//connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(resetConnection()));
	// need ready toggle button in gsServer, client and main Window
    this->show();
}

MainWindow::~MainWindow()
{
	if (gsServer != nullptr) 
    {
        delete gsServer;    // need to make sure theres no lingering mem leaks. Possibly valgrind it?
		gsServer = nullptr;
	}
	if (gsClient != nullptr) 
    {
        delete gsClient;    // need to make sure theres no lingering mem leaks. Possibly valgrind it?
		gsClient = nullptr;
	}
    if (d != nullptr)
    {
        delete d;    // definitely need to make sure theres no lingering mem leaks. Possibly valgrind it?
        d = nullptr;
    }
	delete ui;
}

void MainWindow::StartServer() 
{
	if (ui->pwordLineEdit->displayText().isEmpty() || ui->hnameLineEdit->displayText().isEmpty()) 
    {
		qDebug() << "Input a proper username and password.";
		//further handling for if invalid input
		return;
	}
	qDebug() << "MainWin: Starting server for Global Strike Game.";
	LogEvent(QString("MainWin: Starting server for Global Strike Game."));
	gsClient->password = ui->pwordLineEdit->displayText();
	gsClient->playerName = ui->hnameLineEdit->displayText();
    gsClient->hostFlag = true;
    gsServer = new GlobalStrikeServer(gsClient, d);
    connect(ui->pushButton, SIGNAL(clicked()), gsServer, SLOT(debuggingReadyUp()));
    //d = gsServer
	ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::CloseServer() 
{
	qDebug() << "Closing server";
	if (gsServer != nullptr) 
    {
		delete gsServer;
		gsServer = nullptr; // need to go back and rehandle if there are straggling dynAlloc guys
	}
    gsClient->hostFlag = false;
	// when main window wants to close, need to delete gsClient yourself.
}

void MainWindow::JoinServer() 
{
	if (ui->inputIPLineEdit->displayText().isEmpty() || ui->inputPNumLineEdit->displayText().isEmpty()
		|| ui->inputPNameLineEdit->displayText().isEmpty() || ui->inputPWordLineEdit->displayText().isEmpty()) 
    {
		qDebug() << "Input a proper username and password.";
		// further handling
		return;
	}
	QString ipAddress = ui->inputIPLineEdit->displayText();
	bool ok;
	quint16 portNum = ui->inputPNumLineEdit->displayText().toInt(&ok, 10);
	if (!ok) 
    {
		qDebug() << "Input a decimal port.";
		return;
	}
	gsClient->playerName = ui->inputPNameLineEdit->displayText();
	gsClient->password = ui->inputPWordLineEdit->displayText();
	bool flag = gsClient->connectToServer(ipAddress, portNum);
	if (flag) 
    {
		connect(ui->disconnectButton, SIGNAL(clicked()), this, SLOT(Disconnect()));
	}
	ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::UpdateCountryName(){
    qDebug() << ui->countryButton->property("text");
    if(ui->countryButton->property("text") == "Atlantis"
            && !gsClient->takenCountryNames.contains(QString("Atlantis"))){
        gsClient->preReadyCountryName = QString("Cobra Island");
        ui->countryButton->setProperty("text", "Cobra Island");
    }
    else if(ui->countryButton->property("text") == "Cobra Island"
            && !gsClient->takenCountryNames.contains(QString("Cobra Island"))){
        gsClient->preReadyCountryName = QString("Republic of Texas");
        ui->countryButton->setProperty("text", "Republic of Texas");
    }
    else if(ui->countryButton->property("text") == "Republic of Texas"
            && !gsClient->takenCountryNames.contains(QString("Republic of Texas"))){
        gsClient->preReadyCountryName = QString("West Riverdale");
        ui->countryButton->setProperty("text", "West Riverdale");
    }
    else if(ui->countryButton->property("text") == "West Riverdale"
            && !gsClient->takenCountryNames.contains(QString("West Riverdale"))){
        gsClient->preReadyCountryName = QString("Zathura");
        ui->countryButton->setProperty("text", "Zathura");
    }
    else if(ui->countryButton->property("text") == "Zathura" && !gsClient->takenCountryNames.contains(QString("Zathura"))){
        gsClient->preReadyCountryName = QString("Atlantis");
        ui->countryButton->setProperty("text", "Atlantis");
    }
}

void MainWindow::updateLobbyIPData(QString ipAddressLE, quint16 portNumLE) 
{
	LogEvent(QString("MainWin: Updating lobby IP data for Global Strike Game."));
	ui->connectionIPLineEdit->setText(ipAddressLE); // IP address
	ui->connectionIPLineEdit->setReadOnly(true);
	ui->portNumLineEdit->setText(QString(QString::number(portNumLE))); // port num
	ui->portNumLineEdit->setReadOnly(true);
	qDebug() << "Textboxes appended";
}

void MainWindow::updatePlayerLobbyData(QString name){
    if(!gsClient->hostFlag)
        d->newClientAddition(name);
    ui->tableView->setModel(d->GetLobby());
}

void MainWindow::toggleReadyUpFlag(QString name, QString countryName)
{
    if(!gsClient->hostFlag){
        LogEvent(QString("MainWin: Player Ready Status was updated."));
        d->UpdateReadyStatus(name, countryName);
    }
    ui->tableView->setModel(d->GetLobby());
    //playersReady[playerIDList.indexOf(udpID)] = !(playersReady[playerIDList.indexOf(udpID)]);
}

void MainWindow::updatePlayerScoreData(QString name){
    if(!gsClient->hostFlag){
        d->IncrementScore(name);
    }
    ui->tableView->setModel(d->GetModel());
}

void MainWindow::StartLobby()
{
	ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::JoinLobby()
{
	QIntValidator* intValidator = new QIntValidator(ui->inputPNumLineEdit);
	ui->inputPNumLineEdit->setValidator(intValidator);
	QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
	QRegExp ipRegex("^" + ipRange + "\\." + ipRange + "\\." + ipRange + "\\." + ipRange + "$");
	QRegExpValidator* ipValidator = new QRegExpValidator(ipRegex, this);
	ui->inputIPLineEdit->setValidator(ipValidator);
	ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::HomeLobby()
{
	ui->tabWidget->setCurrentIndex(0);
}

/*
void MainWindow::GameLobby()
{
	if (ui->portNumLineEdit->displayText() == "")
	{
		qDebug() << "Please select a port number.";
		return;
	}
	if (ui->playerNameLineEdit->displayText() == "")
	{
		qDebug() << "Please input a player name.";
		return;
	}
	QString portNum = ui->portNumLineEdit->displayText();
	QString playerName = ui->playerNameLineEdit->displayText();
	receiver->assignPortNum(portNum, playerName);
	// receiver->writeHello();
	// receiver->writeJoinLobbyData();
	ui->tabWidget->setCurrentIndex(3);
} come back to this because the ui->tabwidget stuff is needed
*/

void MainWindow::QuitWindow()
{
	quit* quitWin = new quit();
	quitWin->exec();
}

// Executes when "Ready" button is clicked
void MainWindow::ReadyUp()
{
    gsClient->readyToggle();
    //if (playersReady[0] && playersReady[1] && playersReady[2] && playersReady[3] && playersReady[4])
    //{
		// If all players are ready, game starts
    //	StartGame();
    //}
}

// Executes when All players have selected "Ready button"
void MainWindow::StartGame()
{
	// TODO: need to print "Starting game" to textbox
	qDebug() << "Starting Game";
	// System moves to Gameplay Tab
	ui->tabWidget->setCurrentIndex(4);
	ui->lcdDisplay->display(time);

	// Game timer
	game_timer = new QTimer(this);
	connect(game_timer, &QTimer::timeout, this, &MainWindow::UpdateGameTime);
	game_timer->start(1000);

    connect(gsClient, SIGNAL(animateWhite()), this, SLOT(AnimationWhite()));
    connect(gsClient, SIGNAL(animateWhite()), this, SLOT(AnimationOrange()));
    connect(gsClient, SIGNAL(animateWhite()), this, SLOT(AnimationGreen()));
    connect(gsClient, SIGNAL(animateWhite()), this, SLOT(AnimationYellow()));
    connect(gsClient, SIGNAL(animateWhite()), this, SLOT(AnimationBlack()));

	//sql stuff
	// id, name country, score
	Player p1(1, "One", "Country 1");
    d->AddPlayer(p1);
	Player p2(2, "Two", "Country 2");
    d->AddPlayer(p2);
    Player p3(3, "Three", "Country 3"); // reminder to change because redundant and can cause issues
    d->AddPlayer(p3);
	Player p4(4, "Four", "Country 4");
    d->AddPlayer(p4);
	Player p5(5, "Five", "Country 5");
    d->AddPlayer(p5);
	//DisplayLobby();
}

void MainWindow::DisplayDb()
{
    ui->ResultsTable->setModel(d->GetModel());
}

void MainWindow::DisplayLobby()
{
    ui->tableView->setModel(d->GetLobby());
}

// A function to keep track of the status of the game
void MainWindow::UpdateGameTime()
{
	time--;
	ui->lcdDisplay->display(time);
	if (time == 0)
	{
		EndGame();
	}
}

//launches missile from launching player to desired player
void MainWindow::LaunchMissile(QString target)
{
	if (Missile_cd_time != 100 || Interceptor_cd_time != 100)
	{
		qDebug() << "Cannot launch missile!";
		return;
	}
		qDebug() << "Launching missile to " + target;

        /*if(MissileTimer != nullptr){
            delete MissileTimer;
            MissileTimer = nullptr; potential fix to issue of below memory leak
        }*/
        QString pname_target = gsClient->playerNames.at(gsClient->takenCountryNames.indexOf(target));
        gsClient->launchCommand(pname_target);
		MissileTimer = new QTimer(this);
		connect(MissileTimer, &QTimer::timeout, this, &MainWindow::UpdateMissileCooldownTime);
		MissileTimer->start(50); // input is in ms

		// match player.country to target

		//Picks Animation based on Target.country

		//Displays pixmap animation

		//System queries for success
		//(Did the target player launch an Interceptor?)

		//if successful, update SQL db points for launcher

        // need to delete
}

void MainWindow::LaunchConfirmMissile()
{
	CountrySelection* pick = new CountrySelection();
	pick->exec();
	if (pick->target == "NO_COUNTRY")
	{
		qDebug() << "No country selected";
		return;
	}
	else
	{
		MainWindow::LaunchMissile(pick->target);
	}
}

void MainWindow::UpdateMissileCooldownTime()
{
	Missile_cd_time--;
	ui->progressBar->setValue(Missile_cd_time);
	if (Missile_cd_time == 0)
	{
		// generate rand int
		// select target
		// pick->target = countries[randInt] ???
		// fire
		MissileTimer->stop();
		Missile_cd_time = 100;
		ui->progressBar->setValue(Missile_cd_time);
	}
}

void MainWindow::LaunchInterceptor(QString target)
{
	if (Missile_cd_time != 100 || Interceptor_cd_time != 100)
	{
		qDebug() << "Cannot launch interceptor!";
		return;
	}

    qDebug() << QString("Launching interceptor to " + target);
    //gsClient->launchCommand(QString target);
    // Recommend not starting animation until process launch is received
    // (will emit launchFrom(QString origin))
	// Interceptor timer
    QString pname_target = gsClient->playerNames.at(gsClient->takenCountryNames.indexOf(target));
    gsClient->interceptCommand(pname_target);
	InterceptorTimer = new QTimer(this);
	connect(InterceptorTimer, &QTimer::timeout, this, &MainWindow::UpdateInterceptorCooldownTime);
	InterceptorTimer->start(50); // input is in ms
	// match player.country to target

	//Picks Animation based on Target.country

	//Displays pixmap animation

	//System queries for success
	//(Did the target player launch a missile?)

	//update SQL db points for launcher
}

void MainWindow::LaunchConfirmInterceptor()
{
	CountrySelection* pick = new CountrySelection();
	pick->exec();
	if (pick->target == "NO_COUNTRY")
	{
		qDebug() << "No country selected";
		return;
	}
	else
	{
		MainWindow::LaunchInterceptor(pick->target);
	}
}

void MainWindow::UpdateInterceptorCooldownTime()
{
	Interceptor_cd_time--;
	ui->progressBar_2->setValue(Interceptor_cd_time);
	if (Interceptor_cd_time == 0)
	{
		InterceptorTimer->stop();
		Interceptor_cd_time = 100;
		ui->progressBar_2->setValue(Interceptor_cd_time);
	}
}

void MainWindow::EndGame()
{
	qDebug() << "Ending Game...";
	game_timer->stop();
	MissileTimer->stop();
	InterceptorTimer->stop();
	ui->tabWidget->setCurrentIndex(5);
	DisplayDb();
}

void MainWindow::Disconnect() 
{
	gsClient->client->disconnectFromHost();
    gsClient->playerNames.clear();
    gsClient->takenCountryNames.clear();
	disconnect(ui->disconnectButton, SIGNAL(clicked()), this, SLOT(Disconnect()));
	ui->tabWidget->setCurrentIndex(1);
}


void MainWindow::AnimationGreen(){

    ui->animationLabelGreen->show();
    QMovie* movie = new QMovie(":animationImage.gif");
    ui->animationLabelGreen->setAttribute(Qt::WA_NoSystemBackground);
    ui->animationLabelGreen->setMovie(movie);
    ui->animationLabelGreen->setScaledContents(true);
    movie->start();

    QTimer::singleShot(3000,this,SLOT(cleanGreen()));
}

void MainWindow::cleanGreen(){
    ui->animationLabelGreen->hide();
}

void MainWindow::AnimationBlack(){
    QMovie* movie = new QMovie(":animationImage.gif");
    ui->animationLabelBlack->setAttribute(Qt::WA_NoSystemBackground);
    ui->animationLabelBlack->setMovie(movie);
    ui->animationLabelBlack->setScaledContents(true);
    movie->start();

    QTimer::singleShot(3000,this,SLOT(cleanBlack()));
}

void MainWindow::cleanBlack(){
    ui->animationLabelBlack->hide();
}

void MainWindow::AnimationWhite(){
    QMovie* movie = new QMovie(":animationImage.gif");
    ui->animationLabelWhite->setAttribute(Qt::WA_NoSystemBackground);
    ui->animationLabelWhite->setMovie(movie);
    ui->animationLabelWhite->setScaledContents(true);
    movie->start();

    QTimer::singleShot(3000,this,SLOT(cleanWhite()));
}

void MainWindow::cleanWhite(){
    ui->animationLabelWhite->hide();
}

void MainWindow::AnimationYellow(){
    QMovie* movie = new QMovie(":animationImage.gif");
    ui->animationLabelYellow->setAttribute(Qt::WA_NoSystemBackground);
    ui->animationLabelYellow->setMovie(movie);
    ui->animationLabelYellow->setScaledContents(true);
    movie->start();

    QTimer::singleShot(3000,this,SLOT(cleanYellow()));
}

void MainWindow::cleanYellow(){
    ui->animationLabelYellow->hide();
}

void MainWindow::AnimationOrange(){
    QMovie* movie = new QMovie(":animationImage.gif");
    ui->animationLabelOrange->setAttribute(Qt::WA_NoSystemBackground);
    ui->animationLabelOrange->setMovie(movie);
    ui->animationLabelOrange->setScaledContents(true);
    movie->start();

    QTimer::singleShot(3000,this,SLOT(cleanOrange()));
}

void MainWindow::cleanOrange(){
    ui->animationLabelOrange->hide();
}

void MainWindow::LogEvent(QByteArray data) 
{
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) 
    {
		qDebug() << "logging failed.";
		return;
	}
	file.write(QString("|" + QString::number(lineNum++) + "| ").toUtf8().constData());
	file.write(data.replace('\n', ' '));
	file.write(QString("\n").toUtf8().constData());
	file.close();
}

void MainWindow::LogEvent(QString data) 
{
	// if trying to write stuff like you would comments, LogEvent(QString("This is an example"))
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) 
    {
		qDebug() << "Logging failed.";
		return;
	}
	file.write(QString("|" + QString::number(lineNum++) + "| " + data + "\n").toUtf8().constData());
	file.close();
}

