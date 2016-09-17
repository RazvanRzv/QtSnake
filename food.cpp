#include "food.h"
#include <stdlib.h>

Food::Food(){
    x = new int;
    y = new int;
    *x = rand()%40 * 15;
    *y = rand()%40 * 15;
    setRect(0, 0, 15, 15);
    setPos(*x, *y);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

