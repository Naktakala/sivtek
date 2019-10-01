#ifndef _MESHIO_SURFACEMESH_
#define _MESHIO_SURFACEMESH_

#include <cstdio>
#include <vector>
#include <string>

#include "../meshio.h"

//TODO Move SurfaceMesh to VolumeMesher

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
    std::vector<meshio::Normal> normals;
    std::vector<meshio::Face> faces;




public:
    //IO Silo
    void ImportSilo(std::string const& filename, bool verbose = false, bool timer = false);
    void ExportSilo(std::string const& filename, bool verbose = false, bool timer = false);
    void ExportSiloTest(bool verbose = false, bool timer = false);

    //IO VTK
    void ImportVTK(std::string const& filename, bool verbose = false, bool timer = false);
    void ExportVTK(std::string const& filename, bool verbose = false, bool timer = false);

    //Util Silo
    void SeparateShapes(bool verbose = false, bool timer = false);

};

#endif // SURFACEMESH_H