#include "global.h"

character::character(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) : QGraphicsRectItem (x, y, width, height, parent)
{
    this->setPen(QPen(Qt::blue));
    this->setBrush(QBrush(Qt::blue));
}


void character::keyPressEvent(QKeyEvent* event)
{
    Stick::gamewindow game;
    if(event && (event->key() == Qt::Key_P))
    {
        game.Attack();
        return;
    }
}

Stick::Player::Player()
{
    this->UID = 0;
    this->name = "name";
    this->color = Qt::red;
    this->score = 0;
    this->xpos = 0;
    this->ypos = 0;
    this->health = 5;
    this->ColorSet = false;
}

void Stick::Player::SetAll(unsigned int uid, QString name, QRgb color)
{
    Player *user = new Player();      // New player when function is called.
    this->UID = uid;
    this->name = name;
    this->color = color;
    user->UID = uid;                // Set the UID.
    user->name = name;              // Set the name.
    user->color = color;            // Set the color.
    user->score = 0;                // Set the score.
    players.append(user);           // Append the user to the list.
}

// Set the Player's ID.
void Stick::Player::PlayerUID(unsigned int UID)
{
    Player *user = new Player;      // New player when function is called.
    players[UID]->UID = UID;     // Sets the player's UID.
}
// Set the Player's name.
void Stick::Player::PlayerName(int ID, QString name)
{
    Player *user = new Player;      // New player when function is called.
    players[ID]->name = name;   // Set the player's name.
}
// Set the Player's color.
void Stick::Player::PlayerColor(int ID, QRgb color)
{
    Player *user = new Player;      // New player when function is called.
    players[ID]->color = color;
    players[ID]->ColorSet = true;
}
// Set the Player's score.
void Stick::Player::PlayerScore(int ID, int score)
{
    Player *user = new Player;      // New player when function is called.
    user->score = score;
    //players[ID]->score = score;
}

void Stick::Player::PlayerX(int ID, int pos)
{
    Player *user = new Player;      // New player when function is called.
    players[ID]->xpos = pos;
}

void Stick::Player::PlayerY(int ID, int pos)
{
    Player *user = new Player;      // New player when function is called.
    players[ID]->ypos = pos;
}

unsigned int Stick::Player::ReturnID(int ID)
{
    return players[ID]->UID;
}

QString Stick::Player::ReturnName(int ID)
{
    return players[ID]->name;
}

QRgb Stick::Player::ReturnColor(int ID)
{
    return players[ID]->color;
}

int Stick::Player::ReturnScore(int ID)
{
    Player *user = new Player;      // New player when function is called.
    return user->score;
    //return players[ID]->score;
}

int Stick::Player::ReturnXPos(int ID)
{
    return players[ID]->xpos;
}

int Stick::Player::ReturnYPos(int ID)
{
    return players[ID]->ypos;
}

int Stick::Player::ReturnHealth(int ID)
{
    return players[ID]->health;
}
