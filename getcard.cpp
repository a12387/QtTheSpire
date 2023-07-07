#include "getcard.h"
#include "ui_getcard.h"
#include <QPainter>
#include "game/cards/RandomCard.h"
#include "mainwindow.h"
#include "QSoundEffect"
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

    cards[0] = RandomCard::getAnyCard()->makeCopy();

    while(true)
    {
        cards[1] = RandomCard::getAnyCard()->makeCopy();
        if(*cards[1] != *cards[0])
            break;
        delete cards[1];
    }
    while(true)
    {
        cards[2] = RandomCard::getAnyCard()->makeCopy();
        if(*cards[2] != *cards[1] && *cards[2] != *cards[0])
            break;
        delete cards[2];
    }

    for(int i=0;i<3;i++){
        CardButton *c = new CardButton(cards[i],this);
        c->move(170+i*280,140);
        connect(c,&CardButton::chooseCardButton,this,&GetCard::getCard);
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
    QSoundEffect*e=new QSoundEffect();
    e->setSource(QUrl("qrc:/game/resource/audio/sound/CardSelect.wav"));
    e->play();
    if(mw->d.player->masterDeck.group.size()<21)
    {
        GetCard *gc = new GetCard(parentWidget());
        gc->show();
    }
    delete this;
}
