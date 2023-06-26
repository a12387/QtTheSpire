#include "combatroom.h"
#include "ui_combatroom.h"
#include "mainwindow.h"

CombatRoom::CombatRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombatRoom)
{
    ui->setupUi(this);
    move(0,50);

    mw = (MainWindow*)parent;

    playerWidget = new CreatureWidget(mw->d.player,this);
    if(mw->d.rooms[mw->d.floor]->type == AbstractRoom::MONSTER)
        playerWidget->move(420,120);

    for(auto &i:mw->d.rooms[mw->d.floor]->monsters.monsters)
    {
        monstersWidget.push_back(new CreatureWidget(i,this));
        i->mw=this->mw;
    }
    for(int i = 0; i < monstersWidget.size(); i++)
    {
        monstersWidget[i]->move(120 + 600 * i, 120);
    }

    uc = new UseCard(this);
    uc->move(0,420);

    connect(this,&CombatRoom::preBattle,this,&CombatRoom::initalize);
    connect(this,&CombatRoom::startTurn,this,&CombatRoom::playerAction);
    connect(this,&CombatRoom::endTurn,this,&CombatRoom::monsterAction);

    //emit preBattle();
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
    mw->d.player->drawCard(5);
    for(auto &i:monstersWidget)
    {
        ((AbstractMonster*)(i->c))->createIntent();
        i->setIntent(((AbstractMonster*)(i->c))->intent);
    }
    update();
}
void CombatRoom::monsterAction(){
    for(auto &i:monstersWidget)
    {
        ((AbstractMonster*)(i->c))->act(mw->d.player);
    }
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
