#include "Game.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game * game = new Game();
    game->start();

    return a.exec();
}
