#include "gameenddialog.h"
#include "ui_gameenddialog.h"
#include "mainwindow.h"
#include <QtDebug>

GameEndDialog::GameEndDialog(MainWindow* lobbyScreen, Client* c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameEndDialog)
{
    ui->setupUi(this);
    client = c;
    int thisID = client->getMyID();
    mainWindow = lobbyScreen;
    // Connect close and submit buttons to actions
    connect(ui->ExitLobbypushButton, SIGNAL(clicked(bool)), this, SLOT(Exit()));
    //connect(ui->ExitLobbypushButton, &QPushButton::clicked, lobbyScreen, &MainWindow::DisconnectHandle);
    connect(ui->PlayAgainpushButton, SIGNAL(clicked(bool)), this, SLOT(PlayAgain()));
    connect(ui->PlayAgainpushButton, &QPushButton::clicked, lobbyScreen, &MainWindow::LobbyRefresh);
    connect(client, &Client::SendFinalScores, this, &GameEndDialog::DisplayFinalScores);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finalScores.db");
    if(!db.open())
    {
        qDebug() << db.lastError();
        qDebug() << "Error: unable to connect to database";
        return;
    }

    QSqlQuery q("DROP TABLE scores");
    q.prepare("CREATE TABLE scores(name TEXT, score INT)");
    if(!q.exec())
    {
        qDebug() << db.lastError();
        qDebug() << "Error: database error";
        return;
    }
    model = new QSqlQueryModel(this);

    QByteArray out;
    QTextStream requestMessage(&out, QIODevice::WriteOnly);
    requestMessage << static_cast<int>(MessageType::SendFinalScores) << endl
                   << thisID << endl;
    client->SendByteArray(out);
}

GameEndDialog::~GameEndDialog()
{
    delete ui;
}

void GameEndDialog::PlayAgain()
{
    //this->setDisabled(true);    // Not needed since it is deleted
    this->deleteLater();   // changed from close to deleteLater
}
void GameEndDialog::Exit()
{
    mainWindow->DisconnectHandle();
    mainWindow->show();
    this->deleteLater();
}

void GameEndDialog::DisplayFinalScores(QTextStream& incomingData)
{
    int lobbySize;
    QString name;
    int score;
    SimplePlayer player1;               // Initialize identifiers for all players
    SimplePlayer player2;
    SimplePlayer player3;
    SimplePlayer player4;
    SimplePlayer player5;
    incomingData >> lobbySize;
    SimplePlayer plarray[lobbySize];    // Initialize array for players
    for(int i = 0; i < lobbySize; i++)  // Get name and score for each player
    {
        incomingData >> name >> score;
        switch(i)
        {
        case 0:
            player1.name = name;
            player1.score = score;
            plarray[i] = player1;
            break;
        case 1:
            player2.name = name;
            player2.score = score;
            plarray[i] = player2;
            break;
        case 2:
            player3.name = name;
            player3.score = score;
            plarray[i] = player3;
            break;
        case 3:
            player4.name = name;
            player4.score = score;
            plarray[i] = player4;
            break;
        case 4:
            player5.name = name;
            player5.score = score;
            plarray[i] = player5;
            break;
        }
    }
//    for(int i = 0; i < lobbySize; i++)  // Sort players by score
//    {
//        for(int j = i; ((j>0) && (plarray[j-1].score < plarray[j].score)); j--)
//        {
//            SimplePlayer holder = plarray[j];
//            plarray[j] = plarray[j-1];
//            plarray[j-1] = holder;
//        }
//    }

    QSqlQuery q;
    for(int i = 0; i < lobbySize; i++)
    {
        q.prepare("INSERT INTO scores VALUES(:name, :score)");
        q.bindValue(":name", plarray[i].name);
        q.bindValue(":score", plarray[i].score);
        if(!q.exec())
        {
            db.lastError();
            qDebug() << "Error adding values";
        }
    }

    model->setQuery("SELECT * FROM scores ORDER BY score DESC;");
    ui->tableView->setModel(model);
    db.close();

    QSqlDatabase dab = QSqlDatabase::addDatabase("QSQLITE");
    dab.setDatabaseName("../highscores.db");

    if(!dab.open())
    {
        qDebug() << "Error: unable to open database";
        return;
    }

    QSqlQuery que;
    que.prepare("SELECT * FROM highscores");
    if(!que.exec())
    {
        qDebug() << "Error: unable to locate table";
        return;
    }

    for(int i = 0; i < lobbySize; i++)
    {
        que.prepare("INSERT INTO highscores VALUES(:player, :score)");
        que.bindValue(":player", plarray[i].name);
        que.bindValue(":score", plarray[i].score);
        if(!que.exec())
        {
            dab.lastError();
            qDebug() << "Error adding values";
        }
    }

    dab.close();
}
