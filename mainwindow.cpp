
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
    QWidget *w = new QWidget(this);
    w->setGeometry(0,50,1080,670);
    w->show();
    currentScreen = new Map(true,w);
    currentScreen->show();
    stateBar = new StateBar(this);
    stateBar->show();
}


