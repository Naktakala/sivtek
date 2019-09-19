#ifndef _MESHIO_MESHCONTINUUM_
#define _MESHIO_MESHCONTINUUM_

#include <vector>

#include "../meshio.h"

class meshio::MeshContinuum
{
public:
    std::vector<meshio::Node*> nodes;
    std::vector<meshio::Cell*> cells;
    meshio::SurfaceMesh* mesh_surface;
    std::vector<int> local_cell_indices;
    std::vector<int> cell_local_indices;
    std::vector<int> boundary_cell_indices;

public:
    MeshContinuum()
    {
        this->mesh_surface = nullptr;
    }
};

#endif // MESHCONTINUA_Hontinua