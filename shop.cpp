#include "shop.h"
#include "ui_shop.h"
#include "mainwindow.h"
#include "map.h"
Shop::Shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    move(0,50);

    mw = (MainWindow*)parentWidget();
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

