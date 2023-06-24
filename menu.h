#ifndef MENU_H
#define MENU_H

#include <QWidget>


namespace Ui {
class Menu;
}
class MainWindow;
class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

    MainWindow *mw;
signals:
    void intoGame();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
