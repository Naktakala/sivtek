#ifndef _MESHIO_MESHHANDLER_
#define _MESHIO_MESHHANDLER_

#include <stdio.h>
#include <vector>

#include "../meshio.h"

class meshio::MeshHandler
{
public:
    std::vector<meshio::SurfaceMesh*>         surfacemesh_stack;
};

#endif // MESHHANDLER_H