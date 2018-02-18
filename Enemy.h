#ifndef ENEMY_H
#define ENEMY_H

#include "Tank.h"
#include <QObject>

class Enemy: public QObject, public Tank
{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
};

#endif // ENEMY_H
