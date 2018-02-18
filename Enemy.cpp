#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <cstdlib> // for rand()

#include <QDebug>

Enemy::Enemy()
{
    // set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move the enemy down
    setPos(x(), y() + 5);
    if (pos().y() > scene()->height())
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy deleted";
    }
}
