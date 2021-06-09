#include "helpers.h"

std::string toLower(const std::string& str)
{
    std::string result = "";
    for(auto c: str)
    {
        result += tolower(c);
    }
    return result;
}