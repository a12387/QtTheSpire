#include "creaturewidget.h"
#include "ui_creaturewidget.h"

CreatureWidget::CreatureWidget(AbstractCreature *c,QWidget *parent) :
    QWidget(parent),c(c),
    ui(new Ui::CreatureWidget)
{
    ui->setupUi(this);

    ui->frame->hide();
    image.load(QString::fromStdString(c->imgUrl));
    ui->character->setPixmap(QPixmap::fromImage(image));
    ui->character->setScaledContents(true);
    ui->intent->setStyleSheet("QLabel{backgroundcolor:transparent;}");
    if(c->isPlayer)
        ui->intent->hide();
    setIntent(AbstractMonster::ATTACK);
}
CreatureWidget::~CreatureWidget()
{
    delete ui;
}

void CreatureWidget::enterEvent(QEnterEvent *e)
{
    if(choose == true)
    {
        ui->frame->show();
    }
    QWidget::enterEvent(e);
}
void CreatureWidget::leaveEvent(QEvent *e)
{
    ui->frame->hide();
}
void CreatureWidget::setIntent(AbstractMonster::Intent intent_){
    QPixmap picture;
    switch(intent_){
    case AbstractMonster::ATTACK:picture.load(":/game/resource/intents/attack.png");break;
    case AbstractMonster::ATTACK_DEBUFF:picture.load(":/game/resource/intents/attackDebuff.png");break;
    case AbstractMonster::BUFF:picture.load(":/game/resource/intents/buff.png");break;
    case AbstractMonster::DEBUFF:picture.load(":/game/resource/intents/debuff.png");break;
    case AbstractMonster::DEFEND:picture.load(":/game/resource/intents/defend.png");break;
    }
    ui->intent->setPixmap(picture);
}
