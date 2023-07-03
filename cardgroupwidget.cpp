#include "cardgroupwidget.h"
#include "ui_cardgroupwidget.h"
#include "game/cards/CardGroup.h"
#include "cardbutton.h"
CardGroupWidget::CardGroupWidget(CardGroup *cg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardGroupWidget)
{
    ui->setupUi(this);

    QPushButton *back = new QPushButton(this);
    back->setGeometry(40,500,180,75);
    back->setText("Back");
    back->setStyleSheet("font:bold 20px;");
    connect(back,&QPushButton::clicked,this,[=](){
        close();
    });

    int s = cg->group.size();
    ui->scrollAreaWidgetContents->setMinimumHeight(s/5 * 282 + 30 );
    auto it = cg->group.begin();
    for(int i = 0; i < cg->group.size(); i++)
    {
        CardButton *c = new CardButton(*it,ui->scrollAreaWidgetContents);
        c->move(210 * (i%5) + 30,282 * (i/5) + 30);
        it++;
    }
}

CardGroupWidget::~CardGroupWidget()
{
    delete ui;
}
