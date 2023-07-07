#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    e=new QSoundEffect();
    e->setSource(QUrl("qrc:/game/resource/audio/music/Menu.wav"));
    e->setLoopCount(QSoundEffect::Infinite);
    e->play();
    QWidget *tmp = parentWidget();
    while(tmp->parentWidget()!= nullptr)
    {
        tmp = tmp->parentWidget();
    }
    mw = (MainWindow*)tmp;
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    e->stop();
    emit intoGame();
}

void Menu::on_pushButton_2_clicked(){
    QApplication*app;
    app->exit(0);
}
