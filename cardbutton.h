#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>
#include <QLabel>
#include "./game/cards/AbstractCard.h"
#include "cardwidget.h"
class MainWindow;
class CardButton : public QPushButton
{
    Q_OBJECT
public:
    CardButton(AbstractCard *c,QWidget *p = nullptr,int x = 180,int y = 252);

    AbstractCard *card;

    void enterEvent(QEnterEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *me);
    void mouseReleaseEvent(QMouseEvent *me);
    void resizeEvent(QResizeEvent * re);

    MainWindow *mw;
    QWidget *parent;
    QLabel *bg;
    CardWidget *cardWidget;
    int originX,originY,bigX,bigY;
signals:
    void chooseCard(AbstractCard *card);
    void chooseCardButton(CardButton *card);
};

#endif // CARDBUTTON_H
