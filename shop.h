#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include "cardbutton.h"
#include <QSoundEffect>

namespace Ui {
class Shop;
}
class MainWindow;
class Shop : public QWidget
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent = nullptr);
    ~Shop();

    MainWindow *mw;
    QSoundEffect*e;
private slots:
    void on_continue_2_clicked();
    void buyCard(CardButton*);

private:
    Ui::Shop *ui;
};

#endif // SHOP_H
