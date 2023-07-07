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

void StateBar::update()
{
    ui->HP->setText(QString("%1/%2").arg(mw->d.player->currentHealth).arg(mw->d.player->maxHealth));
    ui->Gold->setText(QString("%1").arg(mw->d.player->gold));
}
void StateBar::on_mapButton_clicked()
{
    if(mw->subScreen == nullptr)
    {
        mw->subScreen = new Map(false,mw->currentScreen);
        mw->subScreen->show();
    }
    else
    {   if(mw->d.floor != 0)
        {
            mw->subScreen->close();
            if(dynamic_cast<Map*>(mw->subScreen))
            {
                mw->subScreen = nullptr;
            }
            else
            {
                mw->subScreen = new Map(false,mw->currentScreen);
                mw->subScreen->show();
            }
        }
    }
}


void StateBar::on_deckButton_clicked()
{
    if(mw->subScreen == nullptr)
    {
        mw->subScreen = new CardGroupWidget(false,&(mw->d.player->masterDeck),mw->currentScreen);
        mw->subScreen->show();
    }
    else
    {
        if(mw->d.floor != 0)
        {
            mw->subScreen->close();
            if(dynamic_cast<CardGroupWidget*>(mw->subScreen))
            {
                mw->subScreen = nullptr;
            }
            else
            {
                mw->subScreen = new CardGroupWidget(false,&(mw->d.player->masterDeck),mw->currentScreen);
                mw->subScreen->show();
            }
        }
    }
}

