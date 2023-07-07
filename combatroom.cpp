#include "combatroom.h"
#include "ui_combatroom.h"
#include "mainwindow.h"
#include "map.h"
#include "menu.h"
#include "statebar.h"
#include <QTimer>

CombatRoom::CombatRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombatRoom)
{
    ui->setupUi(this);
    move(0,50);

    mw = (MainWindow*)parent;

    ui->continue_2->hide();
    ui->death->hide();
    ui->returnBtn->hide();

    playerWidget = new CreatureWidget(mw->d.player,this);
    if(mw->d.rooms[mw->d.floor-1]->type == AbstractRoom::MONSTER)
        playerWidget->move(420,150);

    else if(mw->d.rooms[mw->d.floor-1]->type==AbstractRoom::BOSS)
        playerWidget->move(120,150);

    for(auto &i:mw->d.rooms[mw->d.floor-1]->monsters.monsters)
    {
        monstersWidget.push_back(new CreatureWidget(i,this));
        i->mw=this->mw;
    }
    if(mw->d.rooms[mw->d.floor-1]->type == AbstractRoom::MONSTER)
        for(int i = 0; i < monstersWidget.size(); i++)
        {
            monstersWidget[i]->move(120 + 600 * i, 150);
        }
    else if(mw->d.rooms[mw->d.floor-1]->type==AbstractRoom::BOSS)
    {
        monstersWidget[0]->move(720,150);
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
    uc->setEndButton(true);

    mw->d.player->loseBlock();
    mw->d.player->energy = 3;

    mw->d.player->changePower();
    mw->d.player->drawCard(5);
    for(auto &i:monstersWidget)
    {
        ((AbstractMonster*)(i->c))->createIntent();
        i->setIntent(((AbstractMonster*)(i->c))->intent);
    }
    update();
}
void CombatRoom::monsterAction(){

    uc->setEndButton(false);

    QEventLoop l;
    QTimer::singleShot(1000,&l,SLOT(quit()));
    l.exec();
    l.quit();

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
        QEventLoop l;
        QTimer::singleShot(1000,&l,SLOT(quit()));
        l.exec();
        l.quit();
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
    mw->stateBar->update();

    if(playerWidget->c->currentHealth <= 0)
    {
        uc->close();
        for(auto &i : monstersWidget)
        {
            i->close();
        }
        ui->death->show();
        ui->returnBtn->show();
    }
}
void CombatRoom::on_continue_2_clicked()
{
    if(mw->d.floor == 3)
    {
        mw->subScreen = new Map(true,this);
        mw->subScreen->show();
    }
    else if(mw->d.floor == 4)
    {
        QLabel *l = new QLabel(mw);
        l->setText("You Win!");

        l->setGeometry(360,400,360,100);
        l->setAlignment(Qt::AlignHCenter);
        l->show();
        mw->currentScreen->close();
    }
}
void CombatRoom::showContinueButton()
{
    ui->continue_2->show();
    update();
    delete uc;
}


void CombatRoom::on_returnBtn_clicked()
{
    mw->init();
    mw->stateBar->close();
    close();
}

