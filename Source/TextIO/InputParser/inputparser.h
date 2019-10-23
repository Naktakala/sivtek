#ifndef _TEXTIO_INPUTPARSER_
#define _TEXTIO_INPUTPARSER_

#include "../textio.h"

#include <iterator>

class textio::InputParser
{
public:
    InputParser(int& argc, char** argv)
    {
        for(int i = 1; i < argc; i++)
          input_tokens.emplace_back(std::string(argv[i]));
    }

    std::string GetInputOption(const std::string& cmd_option)
    {
        std::vector<std::string>::iterator string_itr;

        string_itr = std::find(
            input_tokens.begin(),
            input_tokens.end(),
            cmd_option);

        if(string_itr != input_tokens.end() && ++string_itr != input_tokens.end())
            return *string_itr;

        return std::string();
    }

    bool InputOptionExists(const std::string& cmd_option)
    {
        return std::find(input_tokens.begin(),
                         input_tokens.end(),
                         cmd_option) != input_tokens.end();
    }

private:
    std::vector<std::string> input_tokens;
};


#endif