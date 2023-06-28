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

    ui->bg_cost->setPixmap(QPixmap(":/game/resource/bg_energy.png"));
    ui->bg_cost->setScaledContents(true);
    ui->cost->setText(QString::number(card->cost));
    ui->cost->setAlignment(Qt::AlignHCenter);
    ui->cost->setFont(f);
    ui->cost->setStyleSheet("color:white;");

    ui->name->setText(QString::fromStdString(card->name));
    ui->name->setAlignment(Qt::AlignHCenter);
    ui->name->setFont(f);
    ui->name->setStyleSheet("color:white;");
    ui->banner->setPixmap(QPixmap(":/game/resource/banner_common.png"));
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
    ui->cost_2->setText(QString::number(card->cost));
    ui->cost_2->setAlignment(Qt::AlignHCenter);
    ui->cost_2->setFont(f);
    ui->cost_2->setStyleSheet("color:black;");

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
