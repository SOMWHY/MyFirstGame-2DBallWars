#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
using namespace std;
using namespace sf;

int main()
{
    Game game;
    //Game loop
    while (game.IsRunning())
    {
        game.Update();
        game.Render();
    }

    return 0;
}