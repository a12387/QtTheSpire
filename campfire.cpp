#include "campfire.h"
#include "ui_campfire.h"
#include "mainwindow.h"
#include "map.h"
#include <QPainter>
Campfire::Campfire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Campfire)
{
    ui->setupUi(this);
    move(0,50);

    QWidget *tmp = parentWidget();
    while(tmp->parentWidget()!= nullptr)
    {
        tmp = tmp->parentWidget();
    }
    mw = (MainWindow*)tmp;

    ui->continueButton->hide();
}

Campfire::~Campfire()
{
    delete ui;
}

void Campfire::on_cardButton_clicked()
{

    GetCard *gc = new GetCard(this);
    gc->show();



    ui->cardButton->setDisabled(true);

    ui->continueButton->show();
}

void Campfire::on_continueButton_clicked()
{
    mw->subScreen = new Map(true,this);
    mw->subScreen->show();
}

