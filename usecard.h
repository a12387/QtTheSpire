#ifndef USECARD_H
#define USECARD_H

#include <QWidget>
#include "cardbutton.h"
namespace Ui {
class UseCard;
}
class MainWindow;
class UseCard : public QWidget
{
    Q_OBJECT

public:
    explicit UseCard(QWidget *parent = nullptr);
    ~UseCard();

    void update();
    void clear();

    MainWindow *mw;
    QVector<CardButton*> cards;
    CardButton *selectedCard;
private slots:
    void confirm(AbstractCard *c);
private:
    Ui::UseCard *ui;
};

#endif // USECARD_H
