#include "powerwidget.h"
#include "ui_powerwidget.h"

PowerWidget::PowerWidget(AbstractPower*p_,QWidget *parent) :
    p(p_),QWidget(parent),
    ui(new Ui::PowerWidget)
{
    ui->setupUi(this);
    image.load(QString::fromStdString(p->imgPath));
    ui->img->setPixmap(QPixmap::fromImage(image));
    ui->img->setScaledContents(true);
    ui->amount->setText(QString::number(p->amount));
}
PowerWidget::~PowerWidget()
{
    delete ui;
}
