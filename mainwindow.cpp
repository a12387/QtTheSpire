
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "statebar.h"
#include "map.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCursor(*new QCursor(QPixmap(":/game/resource/ui/cursor.png"),0,0));
    currentScreen = new Menu(this);
    currentScreen->show();
    d.player->mw=this;
    connect((Menu*)currentScreen,&Menu::intoGame,this,&MainWindow::startGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    currentScreen = new Map(true,this);
    currentScreen->move(0,50);
    currentScreen->show();
    stateBar = new StateBar(this);
    stateBar->show();
}


