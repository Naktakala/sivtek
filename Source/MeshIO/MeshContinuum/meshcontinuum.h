#ifndef _MESHIO_MESHCONTINUUM_
#define _MESHIO_MESHCONTINUUM_

#include <cstdio>
#include <vector>
#include <string>

#include "../meshio.h"


class meshio::SurfaceMesh
{
public:
    int total_shapes;

    std::vector<int> node_index;
    std::vector<int> mat_index;
    std::vector<int> shape_types;

    std::vector<int> material_list;

    std::vector<std::string> material_names;

    std::vector<meshio::Node*> nodes;
    std::vector<meshio::Cell*> cells;

public:
    //IO Silo
    void ImportSilo(std::string const& filename, bool verbose = false, bool timer = false);
    void ExportSiloTest(bool verbose = false);

    //IO VTK
    void ExportVTK(std::string const& filename, bool verbose = false, bool timer = false);
    void ExportVTKTest(std::string const& filename, bool verbose = false, bool timer = false);

    //Util Silo
    void SeparateShapes(bool verbose = false, bool timer = false);

};

#endif // SURFACEMESH_H