#ifndef CREATUREWIDGET_H
#define CREATUREWIDGET_H

#include <QWidget>
#include "game/core/AbstractCreature.h"
#include "game/monsters/AbstractMonster.h"
namespace Ui {
class CreatureWidget;
}

class CreatureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreatureWidget(AbstractCreature *c,QWidget *parent = nullptr);
    ~CreatureWidget();

    QImage image;
    AbstractCreature *c;
    bool choose = false;
    void setIntent(AbstractMonster::Intent);
private:
    void enterEvent(QEnterEvent *e);
    void leaveEvent(QEvent *e);
    Ui::CreatureWidget *ui;
};

#endif // CREATUREWIDGET_H
