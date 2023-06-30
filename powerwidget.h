#ifndef POWERWIDGET_H
#define POWERWIDGET_H

#include <QWidget>
#include "game/powers/AbstractPower.h"
namespace Ui {
class PowerWidget;
}

class PowerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PowerWidget(AbstractPower*,QWidget *parent = nullptr);
    ~PowerWidget();

    QImage image;
    AbstractPower*p;

    void enterEvent(QEnterEvent*e);
    void leaveEvent(QEvent*e);

private:
    Ui::PowerWidget *ui;
};

#endif // POWERWIDGET_H
