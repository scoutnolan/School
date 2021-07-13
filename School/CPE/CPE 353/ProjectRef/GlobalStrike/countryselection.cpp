#include "countryselection.h"
#include "ui_countryselection.h"

CountrySelection::CountrySelection(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::CountrySelection)
{
	ui->setupUi(this);
	connect(ui->pushButton_Atlantis, SIGNAL(clicked()), this, SLOT(PickAtlantis()));
	connect(ui->pushButton_CI, SIGNAL(clicked()), this, SLOT(PickCI()));
	connect(ui->pushButton_RoT, SIGNAL(clicked()), this, SLOT(PickRoT()));
	connect(ui->pushButton_WR, SIGNAL(clicked()), this, SLOT(PickWR()));
	connect(ui->pushButton_Zathura, SIGNAL(clicked()), this, SLOT(PickZathura()));
}

CountrySelection::~CountrySelection()
{
	delete ui;
}

void CountrySelection::PickAtlantis()
{
	//if(player.country == "Atlantis")
	// qDebug() << "Can not target your own country! Try again."
	// return
	// else
	this->accept();
	// qDebug() << "Picked Atlantis";
	target = "Atlantis";
}

void CountrySelection::PickCI()
{
	this->accept();
	// qDebug() << "Picked Cobra Island";
	target = "Cobra Island";
}

void CountrySelection::PickRoT()
{
	this->accept();
	// qDebug() << "Picked Republic of Texas";
	target = "Republic of Texas";
}

void CountrySelection::PickWR()
{
	this->accept();
	// qDebug() << "Picked West Riverdale";
	target = "West Riverdale";
}

void CountrySelection::PickZathura()
{
	this->accept();
	// qDebug() << "Picked Zathura";
	target = "Zathura";
}
