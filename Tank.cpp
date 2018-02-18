#include "Tank.h"
#include "Bullet.h"
#include <QGraphicsScene>

#include <QDebug>

Tank::Tank() : step(10), speed(1)
{
    qDebug() << "Tank()";
    setRect(0, 0, 40, 40);
}

Tank::~Tank()
{
    qDebug() << "~Tank()";
}

void Tank::shoot()
{
    Bullet * bullet = new Bullet();
    int border_correction = 2; // TODO: remove it later, when imgs are used.
    bullet->setPos(x() + rect().width() / 2 - border_correction, y());
    // Every QGraphics object has a pointer to the scene it is in.
    if (scene())
    {
        scene()->addItem(bullet);
    }
}
