#include "game.h"
#include "menudialog.h"
#include <QDebug>

#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QString>

Game::Game()
{
    QRect poly(0,0, BOARDSIZEX, BOARDSIZEY);
    QPainterPath path;
    path.addRect(poly);

    scene = new QGraphicsScene(0,0,BOARDSIZEX,BOARDSIZEY);
    scene->addPath(path);
    setFixedSize(700,700);
    setScene(scene);

    scoreText = new QGraphicsTextItem();
    scoreText->setHtml("<b>Score: </b>");
    scoreText->setPos(0, -30);
    scene->addItem(scoreText);

//    MenuDialog *mDialog;
//    mDialog = new MenuDialog();
//    mDialog->show();
//    score = new QGraphicsTextItem();
//    score->setHtml(QString::number(head->score));
//    score->setPos(60, -30);
//    scene->addItem(score);
}

void Game::start(){

    head = new Head();
    scene->addItem(head);
    head->setFlag(QGraphicsItem::ItemIsFocusable);
    head->setFocus();

}
