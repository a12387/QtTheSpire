#include "getcard.h"
#include "ui_getcard.h"
#include <QPainter>
#include "game/cards/red/Armaments.h"
#include "game/cards/red/Strike_Red.h"
#include "game/cards/red/Inflame_Red.h"
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

    CardButton *card1 = new CardButton(new Armaments,this);
    card1->move(170,140);
    CardButton *card2 = new CardButton(new Strike_Red,this);
    card2->move(450,140);
    CardButton *card3 = new CardButton(new Inflame_Red,this);
    card3->move(730,140);

    connect(card1,&CardButton::chooseCardButton,this,&GetCard::getCard);
    connect(card2,&CardButton::chooseCardButton,this,&GetCard::getCard);
    connect(card3,&CardButton::chooseCardButton,this,&GetCard::getCard);
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
