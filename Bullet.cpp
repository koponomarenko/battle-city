#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include <QDebug>

Bullet::Bullet(): step(10), speed(1)
{
    setRect(0, 0, 4, 4);

    // Bullet moves every time the timeout() occures.
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); //ms
}

void Bullet::move()
{
    // When the bullet collides with enemies, destroy both.
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            qDebug() << "bullet deleted";
            return;
        }
    }

    setPos(x(), y() - step);
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
