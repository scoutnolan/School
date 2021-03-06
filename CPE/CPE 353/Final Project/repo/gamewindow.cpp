#include "global.h"
#include "ui_gamewindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>

extern int PlayerCount;
extern int myID;
extern QString MyUserName;
extern int MyUserScore;

Stick::gamewindow::gamewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    XMAX = 700;
    YMAX = 500;
    connect(ui->OkButton, SIGNAL(clicked()), this, SLOT(CloseGame()));  //allows players to leave game (for now)
    //connect(ui->Leaderboard, SIGNAL(clicked()), this, SLOT(Leaderboard()));
    ui->OkButton->setFocusPolicy(Qt::NoFocus);

    scene = new QGraphicsScene(0, 0, XMAX, YMAX, this);
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->backGround->setScene(scene);

    Stick::Player PlayerData;
    Player *user = new Player;      // New player when function is called.
    Stick::Jwindow temp;

    Stick::Swindow color;
    int spawnX = 0;
    int spawnY = 0;

    player = new character(spawnX, spawnY, 20, 20);
    ui->playerOneHealth->setText("Player 1: 5");;
    player->setPos(playerOneSpawnX,playerOneSpawnY);
    player->setPen(QPen(color.colorFind()));        // Returns the color of the player.
    player->setBrush(QBrush(color.colorFind()));    // Returns the color of the player and sets it.
    scene->addItem(player);

    target = new QGraphicsEllipseItem(25, -10, 50 ,50);
    target->setPen(QPen(Qt::red));
    target->setBrush(QBrush(Qt::red));
    scene->addItem(target);

    QMainWindow::setWindowModality(Qt::ApplicationModal);
}


void Stick::gamewindow::CloseGame()
{
    close();
}

Stick::gamewindow::~gamewindow()
{
    delete ui;
}

void Stick::gamewindow::keyPressEvent(QKeyEvent* event)     //determines what function to call (move, attack, etc)
{
    QMainWindow::setFocusPolicy(Qt::StrongFocus);
    startTimer(400/10);
    keys[event->key()] = true; QMainWindow::keyPressEvent(event);
}

void Stick::gamewindow::keyReleaseEvent(QKeyEvent* event)     //determines what function to call (move, attack, etc)
{
    QMainWindow::setFocusPolicy(Qt::StrongFocus);
    startTimer(400/10);
    keys[event->key()] = false; QMainWindow::keyReleaseEvent(event);
}

void Stick::gamewindow::timerEvent(QTimerEvent *)
{
    if(keys[Qt::Key_W])
    {
        moveUp(player);

    }
    if(keys[Qt::Key_A])
    {
        moveLeft(player);

    }
    if(keys[Qt::Key_D])
    {
        moveRight(player);

    }
    if(keys[Qt::Key_S])
    {
        moveDown(player);
    }

    if(keys[Qt::Key_P])
    {
        Attack();
    }
    if(keys[Qt::Key_Space])
    {
        dodge();
    }
}

void Stick::gamewindow::SendXYPos(int ID, qreal x, qreal y)
{
    QByteArray out;
    QTextStream outData(&out, QIODevice::WriteOnly);
    outData << static_cast<int>(Message::Moved) << endl << ID << x << endl << y << endl;
    Stick::Hwindow server;
    server.sendtoClients(out);
}


void Stick::gamewindow::moveLeft(QGraphicsRectItem* person)
{
if(person->scenePos().x() > 0)
        {
                person->setPos(person->scenePos().x() - mSpeed, person->scenePos().y());
                {mSpeed = 0.05;}
        }
}

void Stick::gamewindow::moveRight(QGraphicsRectItem* person )
{
        if(person->scenePos().x() < XMAX)
        {
                person->setPos(person->scenePos().x() + mSpeed, person->scenePos().y());
                {mSpeed = 0.05;}
        }
}

void Stick::gamewindow::moveUp(QGraphicsRectItem* person)
{
        if(person->scenePos().y() > 0)
        {
                person->setPos(person->scenePos().x(), person->scenePos().y() - mSpeed);
                //if(mSpeed > 0.1)
                {mSpeed = 0.05;}
        }
}

void Stick::gamewindow::moveDown(QGraphicsRectItem* person)
{
if(person->scenePos().y() < YMAX)
        {
                person->setPos(person->scenePos().x(), person->scenePos().y() + mSpeed);
                //if(mSpeed > 0.1)
                {mSpeed = 0.05;}
        }
}

void Stick::gamewindow::Attack()
{
   if(attackEnabed == 1)
   {
       attackEnabed = 0;
       collision = 0;
       attackCircle = new QGraphicsEllipseItem(player->scenePos().x()-5,player->scenePos().y()-5,30,30);
       attackCircle->setPen(QPen(Qt::green));
       attackCircle->setBrush(QBrush(Qt::green));
       scene->addItem(attackCircle);
       delay();
       if(!scene->collidingItems(target).isEmpty()) // If we collide with the target.
       {
            AttackTarget();         // Call the attack function.
       }
       qDebug()  << hit;
       scene->removeItem(attackCircle);
       attackEnabed = 1;
       collision = 1;
   }
}

void Stick::gamewindow::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Stick::gamewindow::dodge()
{
    this->mSpeed = 0.1;
}


void Stick::gamewindow::getPNum(int number)
{
    playerCount = number;
    //contSetup();
}

void Stick::gamewindow::Leaderboard()
{

    MyLWindow = new Lwindow();
    MyLWindow -> show();
}

void Stick::gamewindow::AttackTarget()
{
    MyUserScore++;
    playerscore++;  // increment the players score.
    DisplayScore(playerscore);
    if(playerscore == 3)
    {
        OnTenHits();
    }
    RespawnTarget();
}

// Respawns the box we are supposed to attack.
// Make the box random.
void Stick::gamewindow::RespawnTarget()
{
    randomx = QRandomGenerator::global()->bounded(600);
    randomy = QRandomGenerator::global()->bounded(450);
    scene->removeItem(target);  // Remove the target.
    target->setPos(QRandomGenerator::global()->bounded(600), QRandomGenerator::global()->bounded(450)); // update random position.
    scene->addItem(target);     // Add the target back.
}

// Updates the score of the player in the box.
void Stick::gamewindow::DisplayScore(int score)
{
    qDebug() << PlayerData->ReturnScore(myID);
    QString username = MyUserName;
    QString words = QString::number(score);
    QString str= username + "'s score: ";
    QByteArray out;
    QTextStream outData(&out, QIODevice::WriteOnly);
    outData << static_cast<int>(Message::Die) << endl << str << endl << words << endl;
    if (myID==0) {
        Hwindow myhwindow;
        myhwindow.sendtoClients(out);
        ui->textBrowser->append(str+words);
    }
    else {
        Jwindow myjwindow;
        myjwindow.sendtoHost(out);
        }
}

// Ends the game and shows the leaderboard for everyone when a player gets to 10 hits.
void Stick::gamewindow::OnTenHits()
{
    CloseGame();
    Leaderboard();
    qDebug() << "10 hits!";
}

void Stick::gamewindow::updateScoreHost(QTextStream& inData)
{
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
    outData << static_cast<int>(Message::Die) << endl << str << endl;
    Hwindow myhwindow;
    myhwindow.sendtoClients(out);
}

void Stick::gamewindow::updateScoreClient(QTextStream& inData)
{
    QString str1, str2, str3, str;
    inData >> str1;
    inData >> str2;
    while (!inData.atEnd()) {
        inData>> str3;
        str2= str2+" "+str3;
    }
    str= str1 + " " +str2;
    ui->textBrowser->append(str);
}
