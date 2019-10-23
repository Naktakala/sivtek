#include "main.h"

#include "MeshIO/MeshContinuum/meshcontinuum.h"
#include "TextIO/InputParser/inputparser.h"

#include <string>
#include <chrono>


int current_meshhandler;

int main(int argc,char **args)
{
  //============================================= Setting up information
  bool verbose = false;
  bool timer = false;


  //============================================= Rudimentary Check
  /* Checks to see if the second argument is specified.
     Extremely barbaric way of checking for command arguments.
     Plan to improve.
   */
  textio::InputParser user_input(argc, args);


  //============================================= Creating Handlers
  auto* new_meshhandler = new meshio::MeshHandler;
  meshhandler_stack.push_back(new_meshhandler);
  auto* new_mesh = new meshio::MeshContinuum;
  new_meshhandler->surfacemesh_stack.push_back(new_mesh);

  //============================================= Start Timer
  auto t1 = std::chrono::high_resolution_clock::now();


  //============================================= Command line parsing
  /* Checks to see if the second argument is specified.
     Extremely barbaric way of checking for command arguments.
     Plan to improve.
   */
  if(user_input.InputOptionExists("-h"))
  {
      std::cout << "Help was called. WIP Section...." << std::endl;
  }


  if(user_input.InputOptionExists("-v"))
  {
      std::cout << "Verbose was set. WIP Section..." << std::endl;
  }


  if(user_input.InputOptionExists("-a"))
  {
      const std::string& filename = user_input.GetInputOption("-a");

      if(!filename.empty())
      {
          std::cout << "Importing Abaqus file:  " << filename << std::endl;
          new_mesh->ImportAbaqus(filename, verbose, timer);
          new_mesh->ExportVTK(filename, verbose, timer);
      }
      else
      {
          std::cout << "Abaqus file not specified!"<< std::endl;
      }

  }


  if(user_input.InputOptionExists("-s"))
  {
    const std::string& filename = user_input.GetInputOption("-s");

    if(!filename.empty())
    {
        std::cout << "Importing Silo file: " << filename << std::endl;
        new_mesh->ImportSilo(filename, verbose, timer);
        new_mesh->ExportVTK(filename, verbose, timer);
    }
    else
    {
        std::cout << "Silo file not specified!"<< std::endl;
    }
  }

  //============================================= Printing out execution time
  auto t2 = std::chrono::high_resolution_clock::now();
  auto d1 = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  std::cout << "Total Execution Time: " << d1 << " ms" << std::endl;
}
