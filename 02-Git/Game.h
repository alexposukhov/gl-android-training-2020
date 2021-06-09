#include <functional>
#include <random>

#include "gesture.h"

class Gesture;

class Game
{
    public:
        Game();
        bool RunGameLoop();
    private:
        void Greet() const;
        Gesture PlayerPickGesture() const;
        bool CheckWinConditions(const Gesture& AI, const Gesture& player) const;
    private:
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;
};