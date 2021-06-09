#pragma once
#include <string>
#include <vector>

struct Gesture
{
    std::string name;
    std::string abbreviation;
    const std::vector<std::string> loseConditions;
    
    bool operator>(const Gesture& rhs) const;
    bool operator==(const Gesture& rhs) const;
};

