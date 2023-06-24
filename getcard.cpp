#include "getcard.h"
#include "ui_getcard.h"
#include <QPainter>
#include "campfire.h"
#include "mainwindow.h"
#include "cardbutton.h"
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

    CardButton *card1 = new CardButton(this);
    card1->move(170,140);
    CardButton *card2 = new CardButton(this);
    card2->move(450,140);
    CardButton *card3 = new CardButton(this);
    card3->move(730,140);

    connect(card1,&CardButton::chooseCard,this,&GetCard::getCard);
    connect(card2,&CardButton::chooseCard,this,&GetCard::getCard);
    connect(card3,&CardButton::chooseCard,this,&GetCard::getCard);
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
void GetCard::getCard(AbstractCard *card)
{
    mw->d.player->masterDeck.addToTop(card);
    if(mw->d.player->masterDeck.group.size()<15)
    {
        GetCard *gc = new GetCard(parentWidget());
        gc->show();
    }
    delete this;
}
