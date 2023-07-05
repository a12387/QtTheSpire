#include "creaturewidget.h"
#include "ui_creaturewidget.h"
#include "QMouseEvent"
#include "combatroom.h"
CreatureWidget::CreatureWidget(AbstractCreature *c,QWidget *parent) :
    QWidget(parent),c(c),
    ui(new Ui::CreatureWidget)
{
    ui->setupUi(this);

    cr = dynamic_cast<CombatRoom*>(parentWidget());
    ui->frame->hide();
    image.load(QString::fromStdString(c->imgUrl));
    ui->character->setPixmap(QPixmap::fromImage(image));
    ui->character->setScaledContents(true);
    ui->intent->setScaledContents(true);
    ui->healthBarText->setText(QString("%1/%2").arg(c->currentHealth).arg(c->maxHealth));
    if(c->isPlayer)
        ui->intent->hide();

    ui->blockAmount->hide();
    ui->blockIcon->hide();
    ui->blockedHealthBar->hide();
}
CreatureWidget::~CreatureWidget()
{
    delete ui;
}
void CreatureWidget::setFrameState(bool b)
{
    if(b)
        ui->frame->show();
    else
        ui->frame->hide();
}
void CreatureWidget::update()
{
    if(c->currentBlock > 0)
    {
        ui->blockAmount->show();
        ui->blockIcon->show();
        ui->blockedHealthBar->show();
        ui->blockAmount->setText(QString("%1").arg(c->currentBlock));
    }
    else
    {
        ui->blockAmount->hide();
        ui->blockIcon->hide();
        ui->blockedHealthBar->hide();
    }
    ui->healthBar->resize(240 * c->currentHealth / c->maxHealth,20);
    ui->healthBarText->setText(QString("%1/%2").arg(c->currentHealth).arg(c->maxHealth));

    for(int i=0;i<powersWidget.size();i++){
        powersWidget[i]->hide();
    }

    powersWidget.clear();
    for(auto i=c->buff.begin();i!=c->buff.end();++i){
        powersWidget.push_back(new PowerWidget(*i,this));
    }
    for(int i=0;i<powersWidget.size();i++){
        powersWidget[i]->move(30*i,260);
        powersWidget[i]->show();
    }
}
void CreatureWidget::enterEvent(QEnterEvent *e)
{
    if(choose == true)
        setFrameState(true);
        
    QWidget::enterEvent(e);
}
void CreatureWidget::leaveEvent(QEvent *e)
{
    if(cr->uc->selectedCreature!=this)
        setFrameState(false);
    QWidget::leaveEvent(e);
}
void CreatureWidget::mouseReleaseEvent(QMouseEvent *me)
{
    if(me->button()==Qt::LeftButton&&choose==true&&cr!=nullptr)
    {
        if(cr->uc->selectedCreature!=this)
        {
            if(cr->uc->selectedCreature != nullptr)
                cr->uc->selectedCreature->setFrameState(false);
            cr->uc->selectedCreature = this;
            cr->uc->setConfirmState(true);
        }
        else
        {
            cr->uc->selectedCreature = nullptr;
            cr->uc->setConfirmState(false);
        }
    }
}
void CreatureWidget::setIntent(AbstractMonster::Intent intent_){
    QPixmap picture;
    switch(intent_){
    case AbstractMonster::ATTACK:picture.load(":/game/resource/intents/attack.png");break;
    case AbstractMonster::ATTACK_DEBUFF:picture.load(":/game/resource/intents/attackDebuff.png");break;
    case AbstractMonster::BUFF:picture.load(":/game/resource/intents/buff.png");break;
    case AbstractMonster::DEBUFF:picture.load(":/game/resource/intents/debuff.png");break;
    case AbstractMonster::DEFEND:picture.load(":/game/resource/intents/defend.png");break;
    case AbstractMonster::ATTACK_DEFEND:picture.load(":/game/resource/intents/attackDefend.png");break;
    default:break;
    }
    ui->intent->setPixmap(picture);
}
void CreatureWidget::turnLeft(){
    image.load(":/game/resource/creature/ironclad_.png");
    ui->character->setPixmap(QPixmap::fromImage(image));
    ui->character->setScaledContents(true);
}
void CreatureWidget::turnRight(){
    image.load(":/game/resource/creature/ironclad.png");
    ui->character->setPixmap(QPixmap::fromImage(image));
    ui->character->setScaledContents(true);
}
