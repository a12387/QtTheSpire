#include "statebar.h"
#include "ui_statebar.h"
#include "map.h"
#include "mainwindow.h"
#include <QPainter>
StateBar::StateBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StateBar)
{
    ui->setupUi(this);
    move(0,0);
    mw = (MainWindow *)parent;
}

StateBar::~StateBar()
{
    delete ui;
}

void StateBar::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.setBrush(QColor(50,50,50));
    p.drawRect(this->rect());
    QWidget::paintEvent(pe);
}

void StateBar::on_mapButton_clicked()
{
    if(!dynamic_cast<Map*>(mw->currentScreen) && map == nullptr)
    {
        map = new Map(false,mw->currentScreen);
        map->show();
    }
    else if(map != nullptr)
    {
        map->close();
        map = nullptr;
    }
}

