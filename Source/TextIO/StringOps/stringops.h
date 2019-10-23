#ifndef _TEXTIO_STRINGOPS_
#define _TEXTIO_STRINGOPS_

#include "../textio.h"

class textio::StringOperations
{
public:
    std::vector<std::string>      string_split(const std::string& kString, char delimiter);
    std::string                   string_chardel(std::string& kString, char remchar);
    std::string                   string_remsubstr(std::string& kString, const std::string& substr);
};

#endif