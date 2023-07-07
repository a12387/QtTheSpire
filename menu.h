#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QSoundEffect>

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
    QSoundEffect*e;
signals:
    void intoGame();
    void exitGame();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
