#include "main.h"

#include "MeshIO/SurfaceMesh/surfacemesh.h"



int current_meshhandler;

int main(int argc,char **args)
{
    bool verbose = true;

    auto* new_meshhandler = new meshio::MeshHandler;
    meshhandler_stack.push_back(new_meshhandler);

    auto* new_surfacemesh = new meshio::SurfaceMesh;
    new_meshhandler->surfacemesh_stack.push_back(new_surfacemesh);

    new_surfacemesh->ExportSiloTest(verbose);
    new_surfacemesh->ImportSilo("Test.silo", verbose);
    new_surfacemesh->ExportVTK("Test", verbose);
}
