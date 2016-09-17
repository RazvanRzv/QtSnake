#include <QApplication>
#include "game.h"

// TO DO: snake move alone - Checked
// TO DO: score  - Checked
// TO DO: highscore
// TO DO: decrease timer (eventually incresease duration when food is eaten)
// TO DO: increase timer (time spent in game)
// TO DO: obstacles
// TO DO: food appear in snake's body
// TO DO: new types of food with different points
// TO DO: pause
// TO DO: menu
// TO DO: Game Over screen
// TO DO: speed
// TO DO: change background color and snake shape


Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->start();

    return a.exec();
}



