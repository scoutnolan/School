#include "global.h"
#include "ui_swindow.h"

Stick::Swindow::Swindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Swindow)
{
    ui->setupUi(this);

    connect(ui->RButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->GButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->BButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->CButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->YButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->GrayButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->WButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->PButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(ui->SetColor, SIGNAL(clicked()), this, SLOT(SetUserColor()));
}

Stick::Swindow::~Swindow()
{
    delete ui;
}

void Stick::Swindow::chooseColor()
{
    if(this->ui->RButton->isChecked())
    {
        favColor = Qt::red;
        qDebug() << "Red Selected" << endl;
    }
    else if(this->ui->GButton->isChecked())
    {
        favColor = Qt::green;
        qDebug() << "Green Selected" << endl;
    }
    else if(this->ui->BButton->isChecked())
    {
        favColor = Qt::blue;
        qDebug() << "Blue Selected" << endl;
    }
    else if(this->ui->CButton->isChecked())
    {
        favColor = Qt::cyan;
        qDebug() << "Cyan Selected" << endl;
    }
    else if(this->ui->PButton->isChecked())
    {
        favColor = Qt::magenta;
        qDebug() << "Pink Selected" << endl;
    }
    else if(this->ui->YButton->isChecked())
    {
        favColor = Qt::yellow;
        qDebug() << "Yellow Selected" << endl;
    }
    else if(this->ui->GrayButton->isChecked())
    {
        favColor = Qt::gray;
        qDebug() << "Gray Selected" << endl;
    }
    else if(this->ui->WButton->isChecked())
    {
        favColor = Qt::white;
        qDebug() << "White Selected" << endl;
    }
}

void Stick::Swindow::SetUserColor()
{
    this->close();
}

void Stick::Swindow::closeEvent(QCloseEvent* event)
{
    emit colorChosen();
    QTimer *timer = new QTimer(this);
    timer->setInterval(3000);
    QMainWindow::closeEvent(event);
}

QRgb Stick::Swindow::colorFind()
{
    return favColor;
}
