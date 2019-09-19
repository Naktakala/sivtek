#ifndef _MESHIO_BOUNDARY_
#define _MESHIO_BOUNDARY_

#include "../SurfaceMesh/surfacemesh.h"
#include "../MeshContinuum/meshcontinuum.h"

class meshio::Boundary
{
public:
    meshio::MeshContinuum initial_mesh_continuum;
    std::vector<meshio::MeshContinuum*> mesh_continua;
};

#endif // BOUNDARY_H