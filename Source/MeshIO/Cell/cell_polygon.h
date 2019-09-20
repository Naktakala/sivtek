#ifndef _MESHIO_CELL_POLYGON_
#define _MESHIO_CELL_POLYGON_

#include "cell.h"

class meshio::CellPolygon : public meshio::Cell
{
public:

    std::vector<int> vertex_indices;
    std::vector<int*> edges;
    std::vector<meshio::Vector> edge_normals;
};

#endif // CELL_POLYGON_H