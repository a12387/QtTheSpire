#ifndef STATEBAR_H
#define STATEBAR_H

#include <QWidget>
#include "map.h"
#include "cardgroupwidget.h"
namespace Ui {
class StateBar;
}
class MainWindow;
class StateBar : public QWidget
{
    Q_OBJECT

public:
    explicit StateBar(QWidget *parent = nullptr);
    ~StateBar();

    void paintEvent(QPaintEvent *pe);
    void update();

    MainWindow* mw;
private slots:
    void on_mapButton_clicked();

    void on_deckButton_clicked();


private:
    Ui::StateBar *ui;
};

#endif // STATEBAR_H
