#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include "game/rooms/AbstractRoom.h"
namespace Ui {
class MapWidget;
}
class MainWindow;
class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(bool selectable,QWidget *parent = nullptr);
    ~MapWidget();

    MainWindow* mw;
signals:
    void room(AbstractRoom *room);
private slots:
    void roomButtonClicked();

private:
    Ui::MapWidget *ui;
};

#endif // MAPWIDGET_H
