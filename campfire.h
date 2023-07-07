#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include <QWidget>
#include "getcard.h"
#include "QSoundEffect"
namespace Ui {
class Campfire;
}
class MainWindow;
class Campfire : public QWidget
{
    Q_OBJECT

public:
    explicit Campfire(QWidget *parent = nullptr);
    ~Campfire();

    MainWindow *mw;
    QSoundEffect*e;
private slots:
    void on_cardButton_clicked();

    void on_continueButton_clicked();

private:
    Ui::Campfire *ui;


    friend class GetCard;
};
#endif // CAMPFIRE_H
