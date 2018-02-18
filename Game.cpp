#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <QTimer>

#include <QDebug>

Game::Game(): width(800), height(600)
{
    // create a scene
    scene = new QGraphicsScene(); // gets the key pressed event 2nd, and passes to the focused item.
    scene->setSceneRect(0, 0, width, height);

    // add a view (a widget to display)
    view = new QGraphicsView(scene); // gets the key pressed event 1st
    view->setFixedSize(width, height);
    view->setFrameStyle(0); // remove scroll bars. TODO: is it the best way?
    view->show();
}

Game::~Game()
{
    delete scene;
    delete player;
    delete view;
}

void Game::start()
{
    // create an item to put into the scene
    player = new Player();
    // add the item to the scene
    scene->addItem(player);
    // Items position is always given in terms of scene coordinates.
    player->setPos(scene->width() / 2  - player->rect().width() / 2, scene->height() - player->rect().height() - 1);
    // make the item focusable (catch key events)
    // Only 1 item at a time can get focuse???
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(2000);
}

void Game::spawnEnemy()
{
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);
}
