#ifndef CREATUREWIDGET_H
#define CREATUREWIDGET_H

#include <QWidget>
#include "game/core/AbstractCreature.h"
#include "game/monsters/AbstractMonster.h"
namespace Ui {
class CreatureWidget;
}
class CombatRoom;
class CreatureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreatureWidget(AbstractCreature *c,QWidget *parent = nullptr);
    ~CreatureWidget();

    QImage image;
    AbstractCreature *c;
    bool choose = false;
    CombatRoom *cr;

    void setIntent(AbstractMonster::Intent);
    void setFrameState(bool b);
    void enterEvent(QEnterEvent *e);
    void leaveEvent(QEvent *e);
    void mouseReleaseEvent(QMouseEvent *me);
private:

    Ui::CreatureWidget *ui;
};

#endif // CREATUREWIDGET_H
