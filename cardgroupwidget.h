#ifndef CARDGROUPWIDGET_H
#define CARDGROUPWIDGET_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
class CardGroupWidget;
}
class CardGroup;
class CardButton;
class CardGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardGroupWidget(bool selectable,CardGroup *cg, QWidget *parent = nullptr,int min = -1,int max = -1);
    ~CardGroupWidget();

    CardGroup *cg;
    QVector<CardButton*> selectedCards;
    bool selectable;
    int min,max;
    QPushButton *btn;
private slots:
    void select(CardButton* c);
private:
    Ui::CardGroupWidget *ui;
};

#endif // CARDGROUPWIDGET_H
