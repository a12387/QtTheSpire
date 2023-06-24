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
    if(c->isPlayer)
        ui->intent->hide();
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
