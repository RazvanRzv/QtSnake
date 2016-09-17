#ifndef SBODY_H
#define SBODY_H

#include <QObject>
#include <QGraphicsRectItem>

class SBody: public QObject, public QGraphicsRectItem{

    Q_OBJECT
public:
    SBody();
};

#endif // SBODY_H
