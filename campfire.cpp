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
    //Get Card
    GetCard *gc = new GetCard(this);
    gc->show();


    ui->cardButton->setDisabled(true);
    ui->relicButton->setEnabled(true);


}
void Campfire::on_relicButton_clicked()
{
    /*
     * getRelic
     */
    ui->continueButton->show();
}
void Campfire::on_continueButton_clicked()
{
    Map *map = new Map(true,this);
    map->show();
}

