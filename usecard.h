#ifndef USECARD_H
#define USECARD_H

#include <QWidget>
#include "cardbutton.h"
#include "creaturewidget.h"
namespace Ui {
class UseCard;
}
class MainWindow;
class CombatRoom;
class UseCard : public QWidget
{
    Q_OBJECT

public:
    explicit UseCard(QWidget *parent = nullptr);
    ~UseCard();

    void update();
    void clear();
    void setConfirmState(bool b);

    MainWindow *mw;
    CombatRoom *cr;
    QVector<CardButton*> cards;
    CardButton *selectedCard;
    CreatureWidget* selectedCreature;
signals:
    void endTurn();
private slots:
    void confirm(AbstractCard *c);
    void useSelectedCard();
private:
    Ui::UseCard *ui;

    void cardSelect(CardButton *c);
    void cancelSelect();
    void changeSelect(CardButton *c);
};

#endif // USECARD_H
