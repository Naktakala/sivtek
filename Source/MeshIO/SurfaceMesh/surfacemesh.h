#ifndef _MESH_SURFACEMESH_
#define _MESH_SURFACEMESH_

#include <cstdio>
#include <vector>
#include <string>

#include "../meshio.h"

//TODO Move SurfaceMesh to VolumeMesher

class meshio::SurfaceMesh
{
public:
    int total_shapes;

    std::string type;

    std::vector<int> node_index;

    std::vector<meshio::Vertex> nodes;
    std::vector<meshio::Normal> normals;
    std::vector<meshio::Face> faces;
    std::vector<meshio::Cell*> cells;




public:
    //IO Obj
    //void ImportObj(std::string const& filename, bool verbose = false);
    //void ExportObj(std::string const& filename, bool verbose = false);

    //IO Silo
    void ImportSilo(std::string const& filename, bool verbose = false);
    void ExportSilo(std::string const& filename, bool verbose = false);
    void ExportSiloTest(bool verbose = false);

    //IO VTK
    void ImportVTK(std::string const& filename, bool verbose = false);
    void ExportVTK(std::string const& filename, bool verbose = false);

    // Utilities
    void UpdateConnections();

    //Util Silo
    void CreateFaces();
    void SeperateShapes();

};

#endif // SURFACEMESH_H