#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);


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
    emit intoGame();
}


void Menu::on_pushButton_2_clicked()
{
    mw->close();
}

