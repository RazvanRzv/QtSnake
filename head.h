#ifndef HEAD_H
#define HEAD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QList>
#include <QKeyEvent>
#include <typeinfo>
#include <QDebug>
#include "sbody.h"
#include "food.h"
#include <QTimer>
#define SNAKESIZE 15

class Head: public QObject, public QGraphicsRectItem{

    Q_OBJECT
public:
    Head();
    void keyPressEvent(QKeyEvent *event);
    void grow();
    void moveBody();
    int s;
    void eatFood();

private slots:
    void moveSnake();
private:
    QList<SBody *> BodyBlocks;
    QList<Food *> Foody;
    QPointF prevPos;
    Food *food;
    QGraphicsTextItem *score;
    QTimer *moveTimer;
    char direction;

};

#endif // HEAD_H
