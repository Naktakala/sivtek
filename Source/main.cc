#include "main.h"

#include "MeshIO/MeshContinuum/meshcontinuum.h"

#include <string>
#include <chrono>


int current_meshhandler;

int main(int argc,char **args)
{
    //============================================= Setting up information
    auto t1 = std::chrono::high_resolution_clock::now();

    bool verbose = false;
    bool timer = true;


    //============================================= Creating Handlers
    auto* new_meshhandler = new meshio::MeshHandler;
    meshhandler_stack.push_back(new_meshhandler);

    auto* new_surfacemesh = new meshio::SurfaceMesh;
    new_meshhandler->surfacemesh_stack.push_back(new_surfacemesh);


    //============================================= Checking inputted filename and stripping extension.
    std::string filename(args[1]);


    //============================================= Function Calls
    new_surfacemesh->ImportSilo(filename, verbose, timer);
    new_surfacemesh->ExportVTK(filename, verbose, timer);


    //============================================= Printing out execution time
    auto t2 = std::chrono::high_resolution_clock::now();
    auto d1 = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "Total Execution Time: " << d1 << " ms" << std::endl;
}
