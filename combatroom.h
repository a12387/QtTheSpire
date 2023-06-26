#ifndef COMBATROOM_H
#define COMBATROOM_H

#include <QWidget>
#include "usecard.h"
#include "creaturewidget.h"
#include "game/monsters/AbstractMonster.h"

namespace Ui {
class CombatRoom;
}
class MainWindow;
class CombatRoom : public QWidget
{
    Q_OBJECT

public:
    explicit CombatRoom(QWidget *parent = nullptr);
    ~CombatRoom();
    void update();
    UseCard *uc;
    MainWindow *mw;
    QVector<CreatureWidget*> monstersWidget;
    CreatureWidget *playerWidget;
signals:
    void preBattle();
    void startTurn();
    void endTurn();
private slots:
    void initalize();
    void playerAction();
    void monsterAction();
private:
    Ui::CombatRoom *ui;
};

#endif // COMBATROOM_H
