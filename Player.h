#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"
#include <QKeyEvent>

class Player: public Tank
{
public:
    Player();

    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
