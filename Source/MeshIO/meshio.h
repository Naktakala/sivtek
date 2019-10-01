#ifndef _MESHIO_
#define _MESHIO_

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
    struct PolyFace;

    class SurfaceMesh;

    class Cell;
    class CellPolygon;
    class CellPolyhedron;

    struct CellIndexMap;
    typedef CellIndexMap NodeIndexMap;

    MeshHandler*           GetCurrentHandler();
}

#include "meshiovector.h"
#include "meshiomatrix3x3.h"
#include "meshiofaces.h"

#endif //MESH_H
