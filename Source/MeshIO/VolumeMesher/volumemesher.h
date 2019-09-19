#ifndef _MATHIO_VOLUMEMESHER_
#define _MATHIO_VOLUMEMESHER_

#include <vector>

#include "../meshio.h"

/**
 *
 * \struct CellIndexMap
 * \brief Struct containing information on the mapping of cell indexes.
 *
 **/
struct meshio::CellIndexMap
{
    int mapped_from;   ///< Value for mapped from.
    int mapped_to;     ///< Value for mapped to.
    int mapped_level;  ///< Value for mapped level.

    //! Constructor
    CellIndexMap()
    {
        mapped_from = -1;
        mapped_to = -1;
        mapped_level = -1;
    }
    CellIndexMap(int from, int to)
    {
        mapped_from = from;
        mapped_to = to;
        mapped_level = -1;
    }
};

class meshio::VolumeMesher
{
public:
std::vector<meshio::CellIndexMap*> cell_ordering;
std::vector<meshio::NodeIndexMap*> node_ordering;
std::vector<int> reverse_node_ordering;

public:
    void CreateTriangleCells();
    void GetBoundaryCells();

    int MapNode(int ireference);
    int ReverseMapNode(int i);
};
#endif // VOLUMEMESHER_H