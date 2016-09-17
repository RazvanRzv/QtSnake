#include "game.h"
#include "food.h"
#include <QBrush>
#include <QGraphicsTextItem>

extern Game *game;

Head::Head(){

    setRect(0,0, SNAKESIZE, SNAKESIZE);
    setPos(300, 300);
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setFocus();

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    SBody *firstBody = new SBody();
    firstBody->setPos(285,300);
    BodyBlocks.prepend(firstBody);
    game->scene->addItem(firstBody);

    food = new Food();
    game->scene->addItem(food);

    s = 0;

    score = new QGraphicsTextItem();
    score->setHtml(QString::number(s));
    score->setPos(60, -30);
    game->scene->addItem(score);

    moveTimer = new QTimer();
    moveTimer->setInterval(50);
    moveTimer->start();
    connect (moveTimer, SIGNAL(timeout()),this, SLOT(moveSnake()));
}

void Head::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up){
        direction = 'u';
        if(y() == 0){
            setPos(x(),y() - 0.001);
            qDebug()<<"Wall was hit";
            // TO DO:  Game Over Screen
        }
        if(y() > 0){
            // try to move in opposite direction
            if(pos().y() == BodyBlocks.last()->pos().y() + 15){
                // TO DO: Game Over Screen
            }
            prevPos = pos();
            setPos(x(), y()-15);
            moveBody();
        }
    }
    else if(event->key() == Qt::Key_Down){
        direction = 'd';
        if(y() == BOARDSIZEX - SNAKESIZE){
            setPos(x(),y()+0.001);
            qDebug()<<"Wall was hit";
            // TO DO:  Game Over Screen
        }
        if (y() < BOARDSIZEY - SNAKESIZE ){
            if(pos().y() == BodyBlocks.last()->pos().y() - 15){
                // TO DO: Game Over Screen
            }
            prevPos = pos();
            setPos(x(), y()+15);
            moveBody();
        }
    }
    else if(event->key() == Qt::Key_Right){
        direction = 'r';
        if(x() == BOARDSIZEX - SNAKESIZE){
            setPos(x()+0.001,y());
            qDebug()<<"Wall was hit";
            // TO DO:  Game Over Screen
        }
        if(x() < BOARDSIZEX - SNAKESIZE){

            if(pos().x() == BodyBlocks.last()->pos().x() - 15){
                // TO DO: Game Over Screen
            }
            prevPos = pos();
            setPos(x()+15, y());
            moveBody();
        }
    }
    else if(event->key() == Qt::Key_Left){
        direction = 'l';
        // if snake hit the margin

        if(x() == 0){
            setPos(x()-0.001,y());
            qDebug()<<"Wall was hit";
            // TO DO:  Game Over Screen
        }

        if(x() > 0){
            if(pos().x() == BodyBlocks.last()->pos().x() + 15){
                // TO DO: Game Over Screen
                qDebug()<<"I have no idea";// TO DO: change background color and snake shape
            }
            prevPos = pos();
            setPos(x()-15, y());
            moveBody();
        }
    }

    else if(event->key() == Qt::Key_Space){
        qDebug()<<"POS: "<<x()<<" "<<y();
        qDebug()<<"BODY POS: "<<BodyBlocks[0]->pos().x()<< " "<<BodyBlocks[0]->pos().y();
//        qDebug()<<"Food POS: "<<Foody.last()->pos().x()<< " "<<Foody.last()->pos().y();
        qDebug()<<"PREV POS: "<<prevPos.x()<< " "<<prevPos.y();
        qDebug()<<s;
        qDebug()<<direction;
    }

    else if(event->key() == Qt::Key_P){
        moveTimer->stop();
    }
    else if(event->key() == Qt::Key_R){
        moveTimer->start();
    }

    eatFood();
}

void Head::moveSnake(){
    if(direction == 'd'){
        if(y() == BOARDSIZEX - SNAKESIZE){
            setPos(x(),y()+0.001);
            qDebug()<<"Wall was hit";
            // TO DO:  Game Over Screen
        }
        if (y() < BOARDSIZEY - SNAKESIZE ){
            if(pos().y() == BodyBlocks.last()->pos().y() - 15){
                // TO DO: Game Over Screen
            }
            prevPos = pos();
            setPos(x(), y()+15);
            moveBody();
        }
    }
    else if (direction == 'u'){
        if(y() == 0){
            setPos(x(),y() - 0.001);
            qDebug()<<"Wall was hit";
            // TO DO:  Game Over Screen
        }
        if(y() > 0){
            // try to move in opposite direction
            if(pos().y() == BodyBlocks.last()->pos().y() + 15){
                // TO DO: Game Over Screen
            }
            prevPos = pos();
            setPos(x(), y()-15);
            moveBody();
        }
    }
    else if(direction == 'l'){
            // if snake hit the margin

            if(x() == 0){
                setPos(x()-0.001,y());
                qDebug()<<"Wall was hit";
                // TO DO:  Game Over Screen
            }

            if(x() > 0){
                if(pos().x() == BodyBlocks.last()->pos().x() + 15){
                    // TO DO: Game Over Screen
                }
                prevPos = pos();
                setPos(x()-15, y());
                moveBody();
            }
        }
    else if(direction == 'r'){
        if(x() == BOARDSIZEX - SNAKESIZE){
            setPos(x()+0.001,y());
            qDebug()<<"Wall was hit";
            // TO DO:  Game Over Screen
        }
        if(x() < BOARDSIZEX - SNAKESIZE){

            if(pos().x() == BodyBlocks.last()->pos().x() - 15){
                // TO DO: Game Over Screen
            }
            prevPos = pos();
            setPos(x()+15, y());
            moveBody();
        }
    }

    eatFood();
}



void Head::eatFood(){
    if(food->pos() == pos()){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::black);
        setBrush(brush);

        grow();

        game->scene->removeItem(food);
        delete food;
        food = new Food();
        game->scene->addItem(food);

    }
    else{ // change head color when food is eaten
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::blue);
        setBrush(brush);
    }

    // TO DO: food appear on snakeBody

    // try to move in opposite direction
    for(int i=0, n = BodyBlocks.size()-1; i<n; ++i){
        if(pos() == BodyBlocks[i]->pos()){
            qDebug()<<"Body was hit";
            // TO DO: Game Over Screen
        }
    }
}

void Head::grow(){
    SBody *body = new SBody();
    BodyBlocks.prepend(body);

    body->setPos(prevPos);
    game->scene->addItem(body);

    s++;

    game->scene->removeItem(score);
    score->setHtml(QString::number(s));
    score->setPos(60, -30);
    game->scene->addItem(score);
}




void Head::moveBody(){
    for(int i=0, n = BodyBlocks.size()-1; i<n; ++i){
        BodyBlocks[i]->setPos(BodyBlocks[i+1]->pos());
    }
    // if start only with head decomment this
//    if(!BodyBlocks.isEmpty()){
        BodyBlocks.last()->setPos(prevPos);
        //    }
}
