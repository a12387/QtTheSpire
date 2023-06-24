#include "cardbutton.h"
#include "getcard.h"
#include "game/cards/red/Strike_Red.h"
#include <QMouseEvent>
#include <QResizeEvent>
CardButton::CardButton(QWidget *p,int x, int y) : QPushButton(p) , card(new Strike_Red)
{
    QWidget *tmp = parentWidget();
    while(tmp->parentWidget()!= nullptr)
    {
        tmp = tmp->parentWidget();
    }
    mw = (MainWindow*)tmp;

    parent = p;

    bg = new QLabel(this);
    bg->move(this->pos());
    bg->resize(this->size());
    QString bgUrl;
    switch(card->type)
    {
    case AbstractCard::ATTACK:
        bgUrl = tr(":/game/resource/bg_attack.png");
        break;
    case AbstractCard::SKILL:
        bgUrl = tr(":/game/resource/bg_skill.png");
        break;
    case AbstractCard::POWER:
        bgUrl = tr(":/game/resource/bg_power.png");
        break;
    default:
        break;
    }
    bg->setPixmap(bgUrl);
    bg->setScaledContents(true);

    cardWidget = new CardWidget(card,this);
    cardWidget->show();

    this->resize(x,y);
    this->setFlat(true);
    this->setMouseTracking(true);
    originX = x;
    originY = y;
    bigX = x * 10 / 9;
    bigY = y * 10 / 9;
}
void CardButton::enterEvent(QEnterEvent *e)
{
    raise();
    this->resize(bigX,bigY);
    QPushButton::enterEvent(e);
}
void CardButton::leaveEvent(QEvent *e)
{
    this->resize(originX,originY);
    QPushButton::leaveEvent(e);
}
void CardButton::mousePressEvent(QMouseEvent *me)
{
    if(me->button() == Qt::LeftButton)
    {
        move(x()+3,y()+3);
    }
}
void CardButton::mouseReleaseEvent(QMouseEvent *me)
{
    if(me->button() == Qt::LeftButton)
    {
        move(x()-3,y()-3);
        emit chooseCard(card);
    }
}

void CardButton::resizeEvent(QResizeEvent* re)
{
    bg->resize(re->size());
    cardWidget->resize(re->size());
}
