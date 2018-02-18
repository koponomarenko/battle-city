#ifndef TANK_H
#define TANK_H

#include <QGraphicsRectItem>

class Tank: public QGraphicsRectItem
{
public:
    Tank();
    virtual ~Tank();

    void shoot();
    int getStep() const { return step; }
    int setSpeed() const {return speed; }

private:
    int step;
    int speed;
};

#endif // TANK_H
