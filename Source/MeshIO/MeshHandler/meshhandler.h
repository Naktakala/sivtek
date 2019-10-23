#ifndef _MESHIO_MESHHANDLER_
#define _MESHIO_MESHHANDLER_

#include <cstdio>
#include <vector>

#include "../meshio.h"

class meshio::MeshHandler
{
public:
    std::vector<meshio::MeshContinuum*>         surfacemesh_stack;
};

#endif // MESHHANDLER_H