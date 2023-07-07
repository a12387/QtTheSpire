#ifndef COMBATROOM_H
#define COMBATROOM_H

#include <QWidget>
#include "usecard.h"
#include "creaturewidget.h"
#include "game/monsters/AbstractMonster.h"
#include <QSoundEffect>

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
    void initalize();
    void update();
    void showContinueButton();
    UseCard *uc;
    MainWindow *mw;
    QVector<CreatureWidget*> monstersWidget;
    CreatureWidget *playerWidget;
    QSoundEffect*e,*d;
signals:
    void startTurn();
    void endTurn();
private slots:  
    void playerAction();
    void monsterAction();
    void on_continue_2_clicked();

    void on_returnBtn_clicked();

private:
    Ui::CombatRoom *ui;
};

#endif // COMBATROOM_H
