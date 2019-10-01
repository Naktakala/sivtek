#include "main.h"

#include "MeshIO/SurfaceMesh/surfacemesh.h"

#include <string>
#include <chrono>


int current_meshhandler;

int main(int argc,char **args)
{
    auto t1 = std::chrono::high_resolution_clock::now();

    bool verbose = false;
    bool timer = true;

    auto* new_meshhandler = new meshio::MeshHandler;
    meshhandler_stack.push_back(new_meshhandler);

    auto* new_surfacemesh = new meshio::SurfaceMesh;
    new_meshhandler->surfacemesh_stack.push_back(new_surfacemesh);

    std::string filename(args[1]);

    size_t lastindex = filename.find_last_of('.');
    std::string rawname = filename.substr(0, lastindex);


    new_surfacemesh->ImportSilo(filename, verbose, timer);
    new_surfacemesh->ExportVTK(rawname, verbose, timer);

    auto t2 = std::chrono::high_resolution_clock::now();
    auto d1 = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "Total Execution Time: " << d1 << " ms" << std::endl;

    //new_surfacemesh->ExportSiloTest(verbose);
    //new_surfacemesh->ImportSilo("A0a_AlignedX_Center_0.silo", verbose);
    //new_surfacemesh->ExportVTK("A0a_AlignedX_Center_0", verbose);
}
