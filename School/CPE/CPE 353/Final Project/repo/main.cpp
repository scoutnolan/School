#include "global.h"
#include <QApplication>
unsigned short HOST_PORT=8080;
int PlayerCount=1;
int myID=0;
int firstGame = 0;
QString MyUserName;
int MyUserScore;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Stick::MainWindow w;
    w.show();
    return a.exec();
}
