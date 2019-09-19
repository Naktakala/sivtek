#ifndef _MESHIO_
#define _MESHIO_

#include "../LogIO/logio.h"

#include <vector>

namespace meshio
{
    class MeshHandler;

    struct Vector;
    typedef Vector Normal;
    typedef Vector Vertex;
    typedef Vector Node;

    struct Matrix3x3;

    struct Face;

    class SurfaceMesh;

    class MeshContinuum;

    class Boundary;

    class Cell;
    class CellTriangle;
    class CellPolygon;

    class Region;
    class EmptyRegion;

    class VolumeMesher;
    struct CellIndexMap;
    typedef CellIndexMap NodeIndexMap;

    MeshHandler*           GetCurrentHandler();
}

#include "meshiovector.h"
#include "meshiomatrix3x3.h"
#include "meshiofaces.h"

#endif //MESH_H
