#include "main.h"

#include "MeshIO/SurfaceMesh/surfacemesh.h"

#include <string>


int current_meshhandler;

int main(int argc,char **args)
{
    bool verbose = false;

    auto* new_meshhandler = new meshio::MeshHandler;
    meshhandler_stack.push_back(new_meshhandler);

    auto* new_surfacemesh = new meshio::SurfaceMesh;
    new_meshhandler->surfacemesh_stack.push_back(new_surfacemesh);

    std::string filename(args[1]);

    size_t lastindex = filename.find_last_of('.');
    std::string rawname = filename.substr(0, lastindex);


    new_surfacemesh->ImportSilo(filename, verbose);
    new_surfacemesh->ExportVTK(rawname, verbose);

    //new_surfacemesh->ExportSiloTest(verbose);
    //new_surfacemesh->ImportSilo("A0a_AlignedX_Center_0.silo", verbose);
    //new_surfacemesh->ExportVTK("A0a_AlignedX_Center_0", verbose);
}
