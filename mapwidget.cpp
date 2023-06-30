#include "mapwidget.h"
#include "ui_mapwidget.h"
#include "map.h"
#include "mainwindow.h"
#include <QLabel>
#include <QScrollArea>
MapWidget::MapWidget(bool selectable,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);

    mw = ((Map *)parent)->mw;

    if(selectable)
    {
        switch(mw->d.floor)
        {
        case 0:
            ui->campfireButton->setEnabled(true);
            break;
        case 1:
            ui->shopButton->setEnabled(true);
            break;
        case 2:
            ui->eliteButton->setEnabled(true);
            break;
        case 3:
            ui->bossButton->setEnabled(true);
            break;
        default:
            break;
        }
    }

    connect(ui->campfireButton,&QPushButton::clicked,this,&MapWidget::roomButtonClicked);
    connect(ui->shopButton,&QPushButton::clicked,this,&MapWidget::roomButtonClicked);
    connect(ui->eliteButton,&QPushButton::clicked,this,&MapWidget::roomButtonClicked);
    connect(ui->bossButton,&QPushButton::clicked,this,&MapWidget::roomButtonClicked);
}

MapWidget::~MapWidget()
{
    delete ui;
}

void MapWidget::roomButtonClicked()
{
    emit room(mw->d.rooms[mw->d.floor]);
}

