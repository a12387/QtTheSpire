#include "map.h"
#include "mainwindow.h"
#include "campfire.h"
#include "shop.h"
#include "combatroom.h"
#include "statebar.h"
#include <QScrollArea>
#include <QPushButton>
#include <QPainter>
Map::Map(bool selectable,QWidget *parent)
    : QWidget(parent)
{
    QWidget *tmp = parentWidget();
    while(tmp->parentWidget()!= nullptr)
    {
        tmp = tmp->parentWidget();
    }
    mw = (MainWindow*)tmp;

    resize(1080,670);
    mapWid = new MapWidget(selectable,this);
    QScrollArea *sa = new QScrollArea(this);
    sa->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    sa->setWidget(mapWid);
    sa->resize(1080,670);
    sa->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //sa->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sa->setFrameShape(QFrame::NoFrame);
    mapWid->show();
    sa->setWindowFlag(Qt::FramelessWindowHint);

    QPushButton *back = new QPushButton(this);
    back->setGeometry(40,500,180,75);
    back->setText("返回");
    back->setStyleSheet("font:bold 20px;");
    connect(back,&QPushButton::clicked,this,[=](){
        close();
    });

    back->setStyleSheet("font: 20pt;border-image: url(:/game/resource/ui/endturn.png);color: rgb(255, 255, 255);");

    if(mw->d.floor == 0)
    {
        back->hide();
    }

    connect(mapWid,&MapWidget::room,this,&Map::intoRoom);
}
void Map::intoRoom(AbstractRoom *room)
{
    mw->d.floor++;
    QWidget *former = mw->currentScreen;
    switch(room->type)
    {
    case AbstractRoom::CAMPFIRE:
        mw->currentScreen = new Campfire(mw);
        break;
    case AbstractRoom::SHOP:
        mw->currentScreen = new Shop(mw);
        break;
    case AbstractRoom::MONSTER:
        mw->currentScreen = new CombatRoom(mw);
        break;
    case AbstractRoom::BOSS:
        mw->currentScreen= new CombatRoom(mw);
        break;
    default:
        break;
    }
    mw->currentScreen->move(0,50);
    mw->currentScreen->show();
    room->screen = mw->currentScreen;
    mw->subScreen = nullptr;
    delete former;
}

