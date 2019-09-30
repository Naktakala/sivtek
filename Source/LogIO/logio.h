#ifndef _LOGIO_
#define _LOGIO_

#ifndef ERROR_CHECK
    #define ERROR_CHECK 1
#endif

#include <string>

#ifndef __FILENAME__
    #define __FILENAME__ (__FILE__ + SOURCE_PATH_SIZE)
#endif

#if ERROR_CHECK
    #define whoopsie(...)                                 \
    {                                                     \
        std::string str = __VA_ARGS__;                    \
        std::cout << "[" <<                               \
        __FILENAME__ << "][" <<                           \
        __FUNCTION__ << "][Line " <<                      \
        __LINE__ << "]::" <<                              \
        str << std::endl;                                 \
    }
#else
    #define whoopsie(...)
#endif

#endif // LOGIO_H