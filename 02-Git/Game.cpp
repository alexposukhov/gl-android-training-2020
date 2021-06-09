#include <algorithm>
#include <iostream>

#include "data.h"
#include "Game.h"
#include "gesture.h"
#include "helpers.h"

using namespace std;

namespace
{
    const string QUIT = "q";
}

Game::Game():
    distribution(0, gestures.size() - 1)
{}

void Game::Greet() const
{
    cout << "Please choose: ";
    for (auto gesture: gestures)
    {
        cout << gesture.name << "(" << gesture.abbreviation << ")" << " - ";
    }
    cout << endl;
}

Gesture Game::PlayerPickGesture() const
{
    std::string pick;
    cin >> pick;
    pick = toLower(pick);
    
    std::string NameOfPickedGesture = "None";
    auto PickedGestureIt = find_if(gestures.begin(), gestures.end(), [&pick](const auto& curr){return curr.abbreviation == pick;});
    if(PickedGestureIt != gestures.end())
    {
        NameOfPickedGesture = PickedGestureIt->name;
    }
    
    return {NameOfPickedGesture, pick, {}};
}

bool Game::CheckWinConditions(const Gesture& AI, const Gesture& player) const
{
    if(player.abbreviation == QUIT)
    {
        return false;
    }
    else if(AI == player)
    {
        cout << "Draw!" << endl;
    }
    else if(AI > player)
    {
        cout << "I win: " << AI.name << " beats " << player.name << endl;
    }
    else 
    {
        cout << "You win: " << player.name << " beats " << AI.name << endl;
    }
    
    return true;
}

bool Game::RunGameLoop()
{
    Greet();
    
    auto PlayerPickedGesture = PlayerPickGesture();
    auto AIpickedGesture = gestures[distribution(generator)];
    
    return CheckWinConditions(AIpickedGesture, PlayerPickedGesture);
}

