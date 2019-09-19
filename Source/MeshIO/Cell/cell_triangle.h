#ifndef _MESH_CELL_TRIANGLE_
#define _MESH_CELL_TRIANGLE_

#include "cell.h"

class meshio::CellTriangle : public meshio::Cell
{
public:
    int vertix_index[3]{};
    int normal_index[3]{};
    int edge_index[3][4]{};

public:
    CellTriangle();
};

meshio::CellTriangle::CellTriangle() :Cell()
{
    for(int i = 0; i < 3; i++)
    {
        vertix_index[i] = -1;
        normal_index[i] = -1;
        edge_index[i][0] = -1;
        edge_index[i][1] = -1;
        edge_index[i][2] = -1;
        edge_index[i][3] = -1;
    }
}

#endif // CELL_TRIANGLE_H