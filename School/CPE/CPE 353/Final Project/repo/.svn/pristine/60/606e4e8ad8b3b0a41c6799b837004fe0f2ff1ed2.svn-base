#include "global.h"
#include "ui_lwindow.h"
extern QString MyUserName;
extern int MyUserScore;
Stick::Lwindow::Lwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lwindow)
{
    ui->setupUi(this);

    Stick::Usernames Object;
    QSqlQuery query;
    query.prepare("INSERT INTO members (name, score)" "VALUES(:name, :score)");
    query.bindValue(":name", MyUserName);
    query.bindValue(":score", MyUserScore);
    query.exec();
    Object.db.open();                                       // Open the database.
    QSqlQueryModel* SetModel = new  QSqlQueryModel;     // New Query Model Object
    SetModel->setQuery("SELECT * FROM members");        // Selects everyone from the members list
    ui->leaderboardView->setModel(SetModel);              // Sets the leaderboard view to the model.
}

Stick::Lwindow::~Lwindow()
{
    delete ui;
}


// Add name and tag count.
