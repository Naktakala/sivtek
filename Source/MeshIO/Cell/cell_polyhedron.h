#ifndef _MESHIO_CELL_POLYHEDRON_
#define _MESHIO_CELL_POLYHEDRON_


#include "cell.h"

class meshio::CellPolyhedron : public meshio::Cell
{
public:

    std::vector<int> vertex_indices;
    std::vector<meshio::PolyFace*> faces;
};

#endif // CELL_POLYHEDRON_H