#ifndef CARDGROUPWIDGET_H
#define CARDGROUPWIDGET_H

#include <QWidget>

namespace Ui {
class CardGroupWidget;
}
class CardGroup;
class CardGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardGroupWidget(CardGroup *cg, QWidget *parent = nullptr);
    ~CardGroupWidget();

    CardGroup *cg;
private:
    Ui::CardGroupWidget *ui;
};

#endif // CARDGROUPWIDGET_H
