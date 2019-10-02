#include "main.h"

#include "MeshIO/MeshContinuum/meshcontinuum.h"

#include <string>
#include <chrono>


int current_meshhandler;

int main(int argc,char **args)
{
    //============================================= Setting up information
    bool verbose = false;
    bool timer = false;


    //============================================= Rudimentary Check
    // Checks to see if the second argument is specified.
    if(argc == 1)
    {
        std::cout << "Program was called, without any commands?" << std::endl;
    }
    else if(argc < 2)
    {
        std::cout << "A file was not specified." << std::endl;
        exit(EXIT_FAILURE);
    }


    //============================================= Start Timer
    auto t1 = std::chrono::high_resolution_clock::now();


    //============================================= Creating Handlers
    auto* new_meshhandler = new meshio::MeshHandler;
    meshhandler_stack.push_back(new_meshhandler);

    auto* new_surfacemesh = new meshio::SurfaceMesh;
    new_meshhandler->surfacemesh_stack.push_back(new_surfacemesh);


    //============================================= Checking inputted filename and stripping extension.
    std::string filename(args[1]);


    //============================================= Function Calls
    new_surfacemesh->ImportSilo(filename, verbose, timer);
    std::cout <<
        "Silo Import Finished." << "\n\n" <<
        "Starting VTK Export." << "\n" <<
    std::endl;
    new_surfacemesh->ExportVTK(filename, verbose, timer);
    std::cout <<
        "Finishing VTK Export." << "\n" <<
    std::endl;


    //============================================= Printing out execution time
    auto t2 = std::chrono::high_resolution_clock::now();
    auto d1 = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "Total Execution Time: " << d1 << " ms" << std::endl;
}
