#ifndef _MESH_CELL_
#define _MESH_CELL_

#include "../meshio.h"


//
//TODO: Provide more information on Cell Class.
//
class meshio::Cell
{
public:
    int cell_global_id;
    int cell_local_id;
    Vertex centroid;

public:
    Cell()
    {
        cell_global_id = -1;
        cell_local_id = -1;
    }
};
#endif //CELL_H
