#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include "mapwidget.h"
class MainWindow;
class AbstractRoom;

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(bool selectable,QWidget *parent = nullptr);

    MainWindow *mw;
    MapWidget *mapWid;
signals:
private slots:
    void intoRoom(AbstractRoom *room);//tmp
};

#endif // MAP_H
