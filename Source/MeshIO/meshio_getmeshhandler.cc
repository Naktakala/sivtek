#include "meshio.h"
#include "MeshHandler/meshhandler.h"



extern std::vector<meshio::MeshHandler*> meshhandler_stack;
extern int current_meshhandler;

meshio::MeshHandler* meshio::GetCurrentHandler()
{
    meshio::MeshHandler* current_handler;

    try
    {
        current_handler = meshhandler_stack.at((unsigned long)current_meshhandler);
    }
    catch(std::out_of_range &err)
    {
        std::cerr << "ERROR: Found an invalid index when retrieving current meshio handler.";
        exit(EXIT_FAILURE);
    }

    return current_handler;
}
