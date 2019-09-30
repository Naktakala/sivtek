#ifndef _MESH_CELL_
#define _MESH_CELL_

#include "../meshio.h"


//
//TODO: Provide more information on Cell Class.
//

// Copying Similar Structure of naming cell types from ChiTech
namespace meshio
{
    enum class CellType
    {
        GHOST = 0,
        SLAB = 1,
        SPHERICAL_SHELL = 2,
        CYLINDRICAL_ANNULUS = 3,
        TRIANGLE = 4,
        QUADRILATERAL = 5,
        POLYGON = 6,
        TETRAHEDRON = 7,
        HEXAHEDRON = 8,
        POLYHEDRON = 9
    };
}

class meshio::Cell
{
public:
    int cell_global_id;
    int cell_local_id;
    int material_id;
    Vertex centroid;

private:
    const CellType cell_type;

public:
    explicit Cell(CellType in_cell_type) : cell_type(in_cell_type)
    {
        cell_global_id = -1;
        cell_local_id = -1;

        material_id = -1;
    }

    virtual ~Cell() {}

public:
    const CellType Type() {return cell_type;}
};
#endif //CELL_H
