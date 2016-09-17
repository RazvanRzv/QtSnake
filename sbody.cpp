#include "sbody.h"
#include <QBrush>

SBody::SBody(){
    setRect(0,0,15,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
