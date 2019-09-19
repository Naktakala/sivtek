#ifndef _MESHIO_REGION_
#define _MESHIO_REGION_

#include "../MeshContinuum/meshcontinuum.h"

class meshio::Region
{
public:
    std::vector<meshio::Boundary*> boundaries;
    std::vector<meshio::MeshContinuum*> mesh_volume_continua;
};

class meshio::EmptyRegion : public meshio::Region
{

};

#endif // REGION_H