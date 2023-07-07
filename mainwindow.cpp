
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "statebar.h"
#include "map.h"
#include "game/cards/AbstractCard.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCursor(*new QCursor(QPixmap(":/game/resource/ui/cursor.png"),0,0));
    setWindowTitle("Slay the Spire");
    setWindowIcon(QIcon(":/game/resource/icon.png"));

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

    currentScreen = new Menu(this);
    currentScreen->show();
    d.init();
    d.player->mw=this;

    connect((Menu*)currentScreen,&Menu::intoGame,this,&MainWindow::startGame);
}
void MainWindow::startGame()
{
    AbstractCard::mw = this;
    currentScreen = new QWidget(this);
    currentScreen->setGeometry(0,50,1080,670);
    subScreen = new Map(true,currentScreen);
    currentScreen->show();
    subScreen->show();
    stateBar = new StateBar(this);
    stateBar->show();
}


