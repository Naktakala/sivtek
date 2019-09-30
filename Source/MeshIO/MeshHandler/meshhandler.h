#ifndef _MESHIO_MESHHANDLER_
#define _MESHIO_MESHHANDLER_

#include <stdio.h>
#include <vector>

#include "../meshio.h"

class meshio::MeshHandler
{
public:
    typedef std::vector<meshio::SurfaceMesh*> SurfaceMeshCollection;
    std::vector<SurfaceMeshCollection*>       surfacemesh_collections;
    std::vector<meshio::SurfaceMesh*>         surfacemesh_stack;

    std::vector<meshio::Cell*> pcells;
};

#endif // MESHHANDLER_H