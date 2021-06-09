#include "gesture.h"
#include "helpers.h"

bool Gesture::operator>(const Gesture& rhs) const
{
    for(auto loseComparison : loseConditions)
    {
        if(rhs.abbreviation == loseComparison)
        {
            return false;
        }
    }
    return true;
}

bool Gesture::operator==(const Gesture& rhs) const
{
    return rhs.abbreviation == abbreviation;
}

