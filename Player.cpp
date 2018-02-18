#include "Player.h"
#include <QGraphicsScene>

#include <QDebug>

Player::Player()
{
    qDebug() << "Player()";
}

void Player::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() - getStep() >= 0)
        {
            setPos(x() - getStep(), y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + rect().width() + getStep() <= scene()->width())
        {
            setPos(x() + getStep(), y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        if (pos().y() - getStep() >= 0)
        {
            setPos(x(), y() - getStep());
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        if (pos().y() + rect().height() + getStep() <= scene()->height())
        {
            setPos(x(), y() + getStep());
        }
    }
    else if (event->key() == Qt::Key_Space)
    {
        shoot();
    }
}
