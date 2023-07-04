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

    bool multiSelect = false;
    int minNum,maxNum;

    void update();
    void clear();
    void setConfirmState(bool b);
    void callCardMultiSelection(int min_,int max_);

    MainWindow *mw;
    CombatRoom *cr;
    QVector<CardButton*> cards;
    CardButton *selectedSingleCard = nullptr;
    AbstractCard *c;
    QVector<CardButton*> selectedMultiCard;
    CreatureWidget* selectedCreature;
signals:
    void endTurn();
private slots:
    void selectCardButton(CardButton *c);
    void useSelectedCard();
    void on_drawPileButton_clicked();

    void on_discardPile_clicked();

    void on_exhaustPile_clicked();

    void on_multiConfirmButton_clicked();

private:
    Ui::UseCard *ui;

    void cardSelect(CardButton *c);
    void cancelSingleSelect();
    void cancelMultiSelect(CardButton *c);
    void changeSelect(CardButton *c);
};

#endif // USECARD_H
