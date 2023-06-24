#ifndef GETCARD_H
#define GETCARD_H

#include <QWidget>
#include "game/cards/AbstractCard.h"

namespace Ui {
class GetCard;
}
class MainWindow;
class GetCard : public QWidget
{
    Q_OBJECT

public:
    explicit GetCard(QWidget *parent = nullptr);
    ~GetCard();

    void paintEvent(QPaintEvent* pe);

    MainWindow *mw;
private slots:
    void getCard(AbstractCard *card);
private:
    Ui::GetCard *ui;
};

#endif // GETCARD_H
