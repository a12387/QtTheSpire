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
    void setEndButton(bool b);
    void callCardMultiSelection(CardGroup *c,int min_,int max_);

    MainWindow *mw;
    CombatRoom *cr;
    QVector<CardButton*> cards;
    CardButton *selectedCard = nullptr;
    AbstractCard *c;
    CreatureWidget* selectedCreature = nullptr;
signals:
    void endTurn();
private slots:
    void selectCardButton(CardButton *c);
    void useSelectedCard();
    void on_drawPileButton_clicked();

    void on_discardPile_clicked();

    void on_exhaustPile_clicked();


private:
    Ui::UseCard *ui;

    void cardSelect(CardButton *c);
    void cancelSelect();
    void changeSelect(CardButton *c);
};

#endif // USECARD_H
