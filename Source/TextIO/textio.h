#ifndef _TEXTIO_
#define _TEXTIO_

#include "../LogIO/logio.h"

#include <string>
#include <vector>

//
//TODO: Expand on TextIO Operations.
//
namespace textio
{
    class Operations
    {
    public:
        // textio_strings.cc
        std::vector<std::string>      string_split(const std::string& kString, char delimiter);

    };
}

#endif // TEXTIO_H