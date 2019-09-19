#include "textio.h"

#include <iostream>
#include <sstream>


std::vector<std::string> textio::Operations::string_split(const std::string& kString, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(kString);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
