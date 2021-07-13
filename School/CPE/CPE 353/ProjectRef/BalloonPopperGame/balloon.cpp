#include "balloon.h"
#include "messagetype.h"
#include <QTimer>

/******************************************************
 * Balloon class should be created by passing in an int
 *
 * Balloon(static_cast<int>(Color::Red);
 *
 * For creating with message from server
 * this can be done with a simple passing of the int
 * that was read
 * i.e.
 *
 * Balloon(int)
 *
 * myColor variable should be used to compare color with
 * pellet that collides with it
 * ****************************************************/

Balloon::Balloon(int color) : QGraphicsPixmapItem ()
{
    switch(color){
    case static_cast<int>(Color::Red):
        setPixmap(QPixmap(":/RedBallon.png"));
        myColor = "Red";
        break;
    case static_cast<int>(Color::Blue):
        setPixmap(QPixmap(":/BlueBalloon.png"));
        myColor = "Blue";
        break;
    case static_cast<int>(Color::Cyan):
        setPixmap(QPixmap(":/CyanBalloon.png"));
        myColor = "Cyan";
        break;
    case static_cast<int>(Color::Pink):
        setPixmap(QPixmap(":/PinkBalloon.png"));
        myColor = "Pink";
        break;
    case static_cast<int>(Color::Black):
        setPixmap(QPixmap(":/BlackBalloon.png"));
        myColor = "Black";
        break;
    case static_cast<int>(Color::Green):
        setPixmap(QPixmap(":/GreenBalloon.png"));
        myColor = "Green";
        break;
    case static_cast<int>(Color::Purple):
        setPixmap(QPixmap(":/PurpleBalloon.png"));
        myColor = "Purple";
        break;
    case static_cast<int>(Color::Yellow):
        setPixmap(QPixmap(":/YellowBalloon.png"));
        myColor = "Yellow";
        break;
    }
}

