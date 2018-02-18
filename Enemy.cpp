#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <random>

#include <QDebug>

Enemy::Enemy()
{
    std::default_random_engine randEng((std::random_device())());
    int randMax = 700; // TODO: this must be "scene.width - rect.width".
    std::uniform_int_distribution<int> uniformDist(0, randMax);
    // set random position
    setPos(uniformDist(randEng), 0);

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
