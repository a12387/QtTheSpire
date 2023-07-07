
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "game/dungeon/Dungeon.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class StateBar;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget *currentScreen;
    QWidget *subScreen;
    StateBar *stateBar;
    Dungeon d;

    void init();
private slots:
    void startGame();
private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
