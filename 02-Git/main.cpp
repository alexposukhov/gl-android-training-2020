/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "data.h"
#include "Game.h"
#include "gesture.h"

using namespace std;

int main()
{
    Game game;
    while(game.RunGameLoop())
    {}
    return 0;
}

