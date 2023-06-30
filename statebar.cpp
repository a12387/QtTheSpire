#include "statebar.h"
#include "ui_statebar.h"
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
    if(dynamic_cast<Map*>(mw->currentScreen))
    {
        if(mw->currentScreen->parentWidget()!=mw)
        {
            mw->currentScreen = mw->currentScreen->parentWidget();
            delete map;
            map = nullptr;
        }
    }
    else if(mw->currentScreen&&mw->currentScreen->parentWidget() == mw)
    {
        map = new Map(false,mw->currentScreen);
        mw->currentScreen = map;
        map->show();
    }
    else
    {
        if(mw->currentScreen)
            mw->currentScreen = mw->currentScreen->parentWidget();
        if(cgw)
        {
            delete cgw;
            cgw = nullptr;
        }

        map = new Map(false,mw->currentScreen);
        mw->currentScreen = map;
        map->show();
    }
}


void StateBar::on_deckButton_clicked()
{
    if(dynamic_cast<CardGroupWidget*>(mw->currentScreen))
    {
        if(mw->currentScreen->parentWidget()!=mw)
        {
            mw->currentScreen = mw->currentScreen->parentWidget();
            delete cgw;
            cgw = nullptr;
        }
    }
    else if(mw->currentScreen&&mw->currentScreen->parentWidget() == mw)
    {
        cgw = new CardGroupWidget(&(mw->d.player->masterDeck),mw->currentScreen);
        mw->currentScreen = cgw;
        cgw->show();
    }
    else
    {
        if(mw->currentScreen)
            mw->currentScreen = mw->currentScreen->parentWidget();
        if(map)
        {
            delete map;
            map = nullptr;
        }

        cgw = new CardGroupWidget(&(mw->d.player->masterDeck),mw->currentScreen);
        mw->currentScreen = cgw;
        cgw->show();
    }
}

