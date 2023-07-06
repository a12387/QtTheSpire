#include "combatroom.h"
#include "ui_combatroom.h"
#include "mainwindow.h"
#include "map.h"

CombatRoom::CombatRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombatRoom)
{
    ui->setupUi(this);
    move(0,50);

    mw = (MainWindow*)parent;

    ui->continue_2->hide();

    playerWidget = new CreatureWidget(mw->d.player,this);
    if(mw->d.rooms[mw->d.floor-1]->type == AbstractRoom::MONSTER)
        playerWidget->move(420,120);

    else if(mw->d.rooms[mw->d.floor-1]->type==AbstractRoom::BOSS)
        playerWidget->move(120,120);

    for(auto &i:mw->d.rooms[mw->d.floor-1]->monsters.monsters)
    {
        monstersWidget.push_back(new CreatureWidget(i,this));
        i->mw=this->mw;
    }
    if(mw->d.rooms[mw->d.floor-1]->type == AbstractRoom::MONSTER)
        for(int i = 0; i < monstersWidget.size(); i++)
        {
            monstersWidget[i]->move(120 + 600 * i, 120);
        }
    else if(mw->d.rooms[mw->d.floor-1]->type==AbstractRoom::BOSS)
    {
        monstersWidget[0]->move(720,120);
    }

    uc = new UseCard(this);
    uc->move(0,420);

    connect(this,&CombatRoom::startTurn,this,&CombatRoom::playerAction);
    connect(uc,&UseCard::endTurn,this,&CombatRoom::monsterAction);

    initalize();
}

CombatRoom::~CombatRoom()
{
    delete ui;
}

void CombatRoom::initalize()
{
    mw->d.player->preBattle();

    emit startTurn();
}
void CombatRoom::playerAction()
{
    //onStartOfTurn();
    mw->d.player->loseBlock();
    mw->d.player->energy = 3;

    mw->d.player->drawCard(5);
    for(auto &i:monstersWidget)
    {
        ((AbstractMonster*)(i->c))->createIntent();
        i->setIntent(((AbstractMonster*)(i->c))->intent);
    }
    update();
}
void CombatRoom::monsterAction(){
    mw->d.player->changePower();
    for(auto &i:monstersWidget)
    {
        ((AbstractMonster*)(i->c))->changePower();
    }
    for(auto &i:monstersWidget)
    {
        i->c->loseBlock();
    }
    for(auto &i:monstersWidget)
    {
        ((AbstractMonster*)(i->c))->act(mw->d.player);
        update();
    }
    emit startTurn();
}
void CombatRoom::update()
{
    for(auto &i:monstersWidget)
    {
        i->update();
    }
    playerWidget->update();
    uc->update();
}

void CombatRoom::on_continue_2_clicked()
{
    mw->subScreen = new Map(true,this);
    mw->subScreen->show();
}
void CombatRoom::showContinueButton()
{
    ui->continue_2->show();
}

