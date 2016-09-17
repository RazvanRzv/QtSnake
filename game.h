#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "head.h"
#include "food.h"
#define BOARDSIZEX 600
#define BOARDSIZEY 600

class Game: public QGraphicsView{
public:
    Game();
    void start();
    QGraphicsScene *scene;
    QGraphicsTextItem *scoreText, *score;
    Head *head;


};

#endif // GAME_H
