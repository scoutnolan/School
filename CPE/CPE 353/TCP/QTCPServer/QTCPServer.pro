#-------------------------------------------------
#
# Project created by QtCreator 2018-11-14T20:44:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTCPServer
TEMPLATE = app

CONFIG+=sdk_no_version_check

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





    class Hwindow : public QMainWindow
    {
        Q_OBJECT
        public:
            explicit Hwindow(QWidget *parent = nullptr);
            ~Hwindow();

        public slots:
            void HostGame();

        private slots:
            void on_HButtonH_clicked();
            void on_PortEditH_textEdited(const QString &arg1);
            void on_BButtonH_clicked();

        private:
            QTcpServer* server;
            Ui::Hwindow *ui;
            LobbyWindow *MyLobbyWindow;
    };


    class TCPserver : public QMainWindow
    {
        Q_OBJECT
        public:
            TCPserver();
        public slots:
            void HostGame();
            void onNewConnection();
            void appendToSocketList(QTcpSocket* socket);
            void displayMessage(const QString& str);
        private slots:
            void on_HButtonH_clicked();
            void on_PortEditH_textEdited(const QString &arg1);
            void on_BButtonH_clicked();
        private:
            QTcpServer* server;
            QList<QTcpSocket*> connection_list;
            Ui::Hwindow *ui;
            LobbyWindow *MyLobbyWindow;
    };



    Stick::TCPServer::Hwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hwindow)
{
    ui->setupUi(this);
    Stick::LobbyWindow object;              // LobbyWindow object so we can add number of players and hosts username.

    connect(ui->HButtonH, SIGNAL(clicked()), this, SLOT(HostGame()));               // If the Host button is clicked, call the HostGame function.
    connect(ui->BButtonH, SIGNAL(clicked()), this, SLOT(on_BButtonH_clicked()));    // If the Back button is clicked, close the game.
    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(StartStickBattle()));    // Start Button
    connect(ui->LButton, SIGNAL(clicked()), this, SLOT(OpenLWindow()));             // Leaderboard button

    // ***** Username and player count ***** //
    QRegularExpression usernameRegExp("[a-zA-Z]{5}");                               // Limits the username to 5 characers
    ui->UserEditH->setValidator(new QRegularExpressionValidator(usernameRegExp));   // Sets the validator to the user edit line text.
    ui->PlayerNumH->setValidator(new QIntValidator(1, 5, this));                    // only allows user to input numbers from 1-5
    QString* NumPlayers = new QString;                                              // New int object for input.
    *NumPlayers = ui->PlayerNumH->text();                                           // Lets the host edit number of players.
    object.PlayerNum = NumPlayers->toInt();                                         // Setting the number of players (for lobbywindow.h/.cpp)
}