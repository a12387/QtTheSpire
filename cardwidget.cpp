#include "cardwidget.h"
#include "ui_cardwidget.h"
#include "cardbutton.h"
#include <QFont>
#include <QPalette>
#include <QResizeEvent>
CardWidget::CardWidget(AbstractCard *card,QWidget *parent) :
    QWidget(parent),card(card),
    ui(new Ui::CardWidget)
{
    ui->setupUi(this);

    QWidget *tmp = parentWidget();
    while(tmp->parentWidget()!= nullptr)
    {
        tmp = tmp->parentWidget();
    }
    mw = (MainWindow*)tmp;

    QFont f;
    f.setPointSize(14);

    if(card->color==AbstractCard::RED)ui->bg_cost->setPixmap(QPixmap(":/game/resource/bg_energy.png"));
    else ui->bg_cost->setPixmap(QPixmap(":/game/resource/bg_energy_colorless.png"));
    ui->bg_cost->setScaledContents(true);

    ui->cost->setFont(f);
    ui->cost->setAlignment(Qt::AlignHCenter);
    ui->cost->setStyleSheet("color:white;");
    ui->cost_2->setAlignment(Qt::AlignHCenter);
    ui->cost_2->setStyleSheet("color:black;");
    if(card->cost != -1 && card->cost != 999)
    {
        ui->cost->setText(QString::number(card->cost));
        ui->cost_2->setText(QString::number(card->cost));
    }
    else if(card->cost == -1)
    {
        ui->cost->setText("X");
        ui->cost_2->setText("X");
    }
    else if(card->cost == 999)
    {
        ui->cost->hide();
        ui->cost_2->hide();
        ui->bg_cost->hide();
    }


    ui->name->setText(QString::fromStdString(card->name));
    ui->name->setAlignment(Qt::AlignHCenter);
    ui->name->setFont(f);
    ui->name->setStyleSheet("color:white;");

    switch(card->rarity){
    case AbstractCard::COMMON:
    case AbstractCard::BASIC:
        ui->banner->setPixmap(QPixmap(":/game/resource/banner_common.png"));break;
    case AbstractCard::UNCOMMON:
        ui->banner->setPixmap(QPixmap(":/game/resource/banner_uncommon.png"));break;
    case AbstractCard::RARE:
        ui->banner->setPixmap(QPixmap(":/game/resource/banner_rare.png"));break;
    }

    ui->banner->setScaledContents(true);

    ui->description->setText(QString::fromStdString(card->description));
    ui->description->setAlignment(Qt::AlignHCenter);
    ui->description->setStyleSheet("color:white;");

    ui->image->setText(tr(""));
    ui->image->setPixmap(QPixmap(QString::fromStdString(card->imgUrl)));
    ui->image->setScaledContents(true);


    QString frameUrl = ":/game/resource/frame_";
    switch(card->type)
    {
    case AbstractCard::ATTACK:
        frameUrl += "attack_";
        break;
    case AbstractCard::POWER:
        frameUrl += "power_";
        ui->frame->setGeometry(10,0,162,145);
        break;
    default:
        frameUrl += "skill_";
        break;
    }
    switch(card->rarity)
    {
    case AbstractCard::RARE:
        frameUrl += "rare.png";
        break;
    case AbstractCard::UNCOMMON:
        frameUrl += "uncommon.png";
        break;
    default:
        frameUrl += "common.png";
        break;
    }
    ui->frame->setText(tr(""));
    ui->frame->setPixmap(QPixmap(frameUrl));
    ui->frame->setScaledContents(true);

    f.setBold(true);
    f.setPointSize(15);
    ui->cost_2->setFont(f);


    for(auto &i : children())
    {
        originGeometry.push_back(((QWidget*)i)->geometry());
        originFontSize.push_back(((QWidget*)i)->font().pointSize());
    }
}

CardWidget::~CardWidget()
{
    delete ui;
}

void CardWidget::resizeEvent(QResizeEvent *re)
{
    float ratio_x = float(re->size().width()) / 180.0f;
    float ratio_y = float(re->size().height()) / 252.0f;

    QObjectList l = this->children();
    for(int i = 0; i < l.size(); i++)
    {
        QLabel *p = (QLabel*)l[i];
        int x = originGeometry[i].x() * ratio_x;
        int y = originGeometry[i].y() * ratio_y;
        int w = originGeometry[i].width() * ratio_x;
        int h = originGeometry[i].height() * ratio_y;
        p->setGeometry(x,y,w,h);

        QFont f = p->font();
        int newSize = qRound(sqrt(ratio_x * ratio_y) * originFontSize[i]);
        f.setPointSize(newSize);
        p->setFont(f);
    }
}
