#include "stringops.h"

#include <iostream>
#include <fstream>
#include <sstream>


std::vector<std::string> textio::StringOperations::string_split(const std::string& kString, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::string trimmed_token;
    std::istringstream tokenStream(kString);


    while (std::getline(tokenStream, token, delimiter))
    {
        trimmed_token = string_chardel(token, ' ');
        tokens.push_back(trimmed_token);
    }
    return tokens;
}

std::string textio::StringOperations::string_chardel(std::string& kString, char remchar)
{
    kString.erase(std::remove(kString.begin(), kString.end(), remchar), kString.end());
    return kString;
}

std::string textio::StringOperations::string_remsubstr(std::string& kString, const std::string& substr)
{
    size_t position;
    std::string token;

    while((position = kString.find(substr)) != std::string::npos)
    {
       token = kString.erase(position, substr.length());
    }

    return token;
}