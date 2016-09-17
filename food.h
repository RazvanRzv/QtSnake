#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QPoint>
#include <QBrush>

class Food: public QObject, public QGraphicsEllipseItem{

    Q_OBJECT
public:
    Food();

private:
    int *x,*y;
};

#endif // FOOD_H
