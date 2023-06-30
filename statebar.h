#ifndef STATEBAR_H
#define STATEBAR_H

#include <QWidget>
#include "map.h"
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

    MainWindow* mw;
    Map *map = nullptr;
private slots:
    void on_mapButton_clicked();

private:
    Ui::StateBar *ui;
};

#endif // STATEBAR_H
