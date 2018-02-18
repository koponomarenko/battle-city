#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>

class Game: public QObject
{
    Q_OBJECT
public:
    Game();
    virtual ~Game();
    void start();

private:
    QGraphicsView * view;
    QGraphicsScene * scene;
    Player * player;
    //Score * score;
    //Health * health;

    int width;
    int height;

public slots:
    void spawnEnemy();
};

#endif // GAME_H
