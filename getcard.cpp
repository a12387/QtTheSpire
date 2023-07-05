#include "getcard.h"
#include "ui_getcard.h"
#include <QPainter>
#include "game/cards/RandomCard.h"
#include "mainwindow.h"
GetCard::GetCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GetCard)
{
    ui->setupUi(this);
    this->setAutoFillBackground(false);

    QWidget *tmp = parentWidget();
    while(tmp->parentWidget()!= nullptr)
    {
        tmp = tmp->parentWidget();
    }
    mw = (MainWindow*)tmp;

    RandomCard*cards[3]={};
    for(int i=0;i<3;i++){
        cards[i]=new RandomCard(this);
        cards[i]->c->move(170+i*280,140);
        connect(cards[i]->c,&CardButton::chooseCardButton,this,&GetCard::getCard);
    }
}
GetCard::~GetCard()
{
    delete ui;
}

void GetCard::paintEvent(QPaintEvent *pe)
{

    QPainter p(this);
    p.setBrush(QColor(0,0,0,200));
    p.drawRect(this->rect());
    QWidget::paintEvent(pe);
}
void GetCard::getCard(CardButton *card)
{
    mw->d.player->masterDeck.addToTop(card->card);
    if(mw->d.player->masterDeck.group.size()<15)
    {
        GetCard *gc = new GetCard(parentWidget());
        gc->show();
    }
    delete this;
}
