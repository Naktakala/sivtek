#include "meshcontinuum.h"

#include "../Cell/cell.h"
#include "../Cell/cell_polyhedron.h"

#include "../../TextIO/StringOps/stringops.h"

#include <iostream>
//#include <algorithm>
#include <chrono>
#include <fstream>
#include <vector>
#include <set>




extern std::vector<meshio::MeshHandler*> meshhandler_stack;


// ****************************************************************************
//
// ****************************************************************************
void meshio::MeshContinuum::ImportAbaqus(std::string const &filename, bool verbose, bool timer)
{
    //============================================= Setting timer
    auto a1 = std::chrono::high_resolution_clock::now();

    //============================================= Verbose Commands
    if(verbose)
    {
        std::cout << "\n==================================================" << std::endl;
    }


    //============================================= Opening file
    std::ifstream file;
    file.open(filename);
    std::cout << "Loading Abaqus file: " << filename << (!file.is_open() ? " failed!\n" : " succeeded! \n\n");


    //============================================= Giant block of Variables
    //const int hex_ordering[24] = {0,3,2,1,
    //                              4,5,6,7,
    //                              4,0,1,5,
    //                              4,2,3,7,
    //                              7,3,0,4,
    //                              5,1,2,6};
    const int hex_ordering[24] = {4,5,6,7,
                                  0,3,2,1,
                                  4,0,1,5,
                                  3,7,6,2,
                                  6,5,1,2,
                                  0,4,7,3};

    std::string type;
    std::string line;
    std::string word;
    std::string delimiter = ",";
    std::vector<std::string> sub_string;
    std::vector<std::string> sub_sub_string;

    textio::StringOperations split;

    int counter = 0;
    int material_count = 0;

    bool capture_nodes = false;
    bool capture_elements = false;


    //============================================= Begin Parsing
    while(std::getline(file,line))
    {
        //============================================= Variables
        /*
         * Why is the counter here and not at the end?
         * Just wanted to be lazy and avoid writing code to skip
         * the first line...
         */
        counter++;
        sub_string = split.string_split(line, ',');
        type       = sub_string.at(0);

        //============================================= Barbaric way of parsing file.
        if(type == "*NODE")
        {
            capture_nodes = true;
            continue;
        }
        else if(type == "**")
        {
            capture_nodes = false;
        }

        //============================================= Whoop Capturing Node Info
        if(capture_nodes)
        {
            auto *new_node = new meshio::Node;
            new_node->xComp = std::stod(sub_string.at(1));
            new_node->yComp = std::stod(sub_string.at(2));
            new_node->zComp = std::stod(sub_string.at(3));
            nodes.push_back(new_node);

            if(verbose)
            {
                std::cout <<
                          sub_string.at(0) << " " <<
                          sub_string.at(1) << " " <<
                          sub_string.at(2) << " " <<
                          sub_string.at(3) << " " <<
                          std::endl;
            }
        }


        //============================================= More barbaric file parsing...
        if(type == "*ELEMENT")
        {
            capture_elements = true;

            //============================================= Storing material info.
            auto mat_name = split.string_remsubstr(sub_string.at(2), "ELSET=");
            this->material_names.push_back(mat_name);
            this->material_list.push_back(material_count++);

            continue;
        }
        else if(type == "**")
        {
            capture_elements = false;
        }

        //============================================= Whoop Capturing Element Info
        if(capture_elements)
        {
            // Maybe I should a debug command on top of verbose?
            //if(verbose){std::cout << line << std::endl;}
            int curloc = -1;

            //============================================= Building the nodelist
            for(int i = 1; i <= 8; i++)
            {
                this->node_index.push_back(stoi(sub_string.at((unsigned long) i)) - 1);
                if(verbose){std::cout << stoi(sub_string.at((unsigned long) i)) << std::endl;}
            }

            auto* new_cell = new meshio::CellPolyhedron;
            for(int f = 0; f < 6; f++)
            {
                auto new_face = new meshio::PolyFace;
                for(int v = 0; v < 4; v++)
                {
                    curloc++;
                    new_face->vertix_indices.push_back(this->node_index.at((unsigned long)hex_ordering[curloc]));
                    if(verbose)
                    {
                        std::cout <<
                        "Curloc::Order::Value       " <<
                        curloc << "::" <<
                        hex_ordering[curloc] << "::" <<
                        this->node_index.at((unsigned long) hex_ordering[curloc]) <<
                        std::endl;
                    }
                }
                new_cell->faces.push_back(new_face);
            }
            new_cell->material_id = material_count;
            cells.push_back(new_cell);
            this->node_index.clear();
        }
    }

    std::cout << "Total Nodes: " << nodes.size() << std::endl;
    std::cout << "Total Cells: " << cells.size() << std::endl;
    std::cout << "Total Mats : " << material_list.size() << "\n" << std::endl;

    //============================================= Setting timer
    auto a2 = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::milliseconds>( a2 - a1 ).count();
    if(timer){std::cout << "ImportAbaqus(): Total Execution Time: " << delta << " ms\n" << std::endl;}


    //============================================= Verbose Commands
    if(verbose){std::cout << "==================================================" << std::endl;}
}

