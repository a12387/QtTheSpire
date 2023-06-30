#include "shop.h"
#include "ui_shop.h"
#include "mainwindow.h"
#include "map.h"
#include "cardbutton.h"
#include "game/cards/red/Armaments.h"
Shop::Shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    move(0,50);

    mw = (MainWindow*)parentWidget();
    CardButton*c=new CardButton(new Armaments,this);
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_continue_2_clicked()
{
    mw->d.floor = 2;
    Map *map = new Map(true,this);
    map->show();
}

