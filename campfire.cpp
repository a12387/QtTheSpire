#include "campfire.h"
#include "ui_campfire.h"
#include "mainwindow.h"
#include "map.h"
#include <QPainter>
Campfire::Campfire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Campfire)
{
    ui->setupUi(this);
    move(0,50);

    e=new QSoundEffect(this);
    e->setSource(QUrl("qrc:/game/resource/audio/music/Shrine.wav"));
    e->setLoopCount(QSoundEffect::Infinite);
    e->play();
    QWidget *tmp = parentWidget();
    while(tmp->parentWidget()!= nullptr)
    {
        tmp = tmp->parentWidget();
    }
    mw = (MainWindow*)tmp;
    ui->bg->setPixmap(QPixmap(":/game/resource/scenes/bonfire1.jpg"));
    ui->bg->setScaledContents(true);
    ui->continueButton->hide();
}

Campfire::~Campfire()
{
    delete ui;
}

void Campfire::on_cardButton_clicked()
{

    GetCard *gc = new GetCard(this);
    gc->show();

    ui->bg->setPixmap(QPixmap(":/game/resource/scenes/bonfire2.jpg"));
    ui->bg->setScaledContents(true);

    ui->cardButton->setDisabled(true);
    ui->cardButton->hide();

    ui->continueButton->show();
}

void Campfire::on_continueButton_clicked()
{
    mw->subScreen = new Map(true,this);
    mw->subScreen->show();
}

