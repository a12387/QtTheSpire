#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include "game/cards/AbstractCard.h"

namespace Ui {
class CardWidget;
}
class MainWindow;
class CardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardWidget(AbstractCard *card, QWidget *parent = nullptr);
    ~CardWidget();

    MainWindow *mw;
    AbstractCard *card;
    QVector<QRect> originGeometry;
    QVector<int>   originFontSize;
    void resizeEvent(QResizeEvent *re);
private:
    Ui::CardWidget *ui;
};

#endif // CARDWIDGET_H
