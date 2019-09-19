//#include "surfacemesh.h"
//#include "../../TextIO/textio.h"
//
//#include <fstream>
//#include <iomanip>
//
//
//
//extern std::vector<meshio::MeshHandler*> meshhandler_stack;
//// ****************************************************************************
////
//// ****************************************************************************
//void meshio::SurfaceMesh::ImportObj(std::string const &filename, bool verbose)
//{
//
//    if(verbose)
//    {
//        //std::cout << "================================================================================ \n\n" ;
//        std::cout << "\n" << "Loading OBJ file " << filename << "\n";
//    }
//
//    int counter = 0;
//    std::ifstream file;
//    file.open(filename);
//
//    if(!file.is_open())
//    {
//        std::cout << "Error opening OBJ file " << filename << "\n";
//    }
//    else
//    {
//        if(verbose)
//        {
//            std::cout << "File " << filename << "loaded successfully." << "\n";
//        }
//    }
//
//
//    std::string line;
//    std::string word;
//    std::string delimiter = " ";
//    std::vector<std::string> sub_str;
//    std::vector<std::string> sub_sub_str;
//
//    //auto* sm = new meshio::SurfaceMesh;
//    textio::Operations split;
//
//    if(verbose)
//    {
//        std::cout << "Outputting file below:" << "\n\n";
//        std::cout << "================================================================================ \n" ;
//    }
//
//    while(std::getline(file, line))
//    {
//        counter++;
//        sub_str = split.string_split(line, ' ');
//        type = sub_str.at(0);
//
//        if(type == "v")
//        {
//            auto *new_vertex = new meshio::Vertex;
//            new_vertex->xComp = std::stod(sub_str.at(1));
//            new_vertex->yComp = std::stod(sub_str.at(2));
//            new_vertex->zComp = std::stod(sub_str.at(3));
//            this->nodes.push_back(*new_vertex);
//
//            if(verbose)
//            {
//                std::cout << "Line " <<
//                          counter << ": v " <<
//                          new_vertex->xComp << " " <<
//                          new_vertex->yComp << " " <<
//                          new_vertex->zComp << "\n";
//            }
//        }
//        else if(type == "vn")
//        {
//            auto *new_normal = new meshio::Vertex;
//            new_normal->xComp = std::stod(sub_str.at(1));
//            new_normal->yComp = std::stod(sub_str.at(2));
//            new_normal->zComp = std::stod(sub_str.at(3));
//            this->normals.push_back(*new_normal);
//
//            if(verbose)
//            {
//                std::cout << "Line " <<
//                          counter << ": vn " <<
//                          new_normal->xComp << " " <<
//                          new_normal->yComp << " " <<
//                          new_normal->zComp << "\n";
//            }
//        }
//        else if(type == "f")
//        {
//            int total_vertices = (int) sub_str.size() - 1;
//            auto *new_face = new meshio::Face;
//
//            for(int i = 1; i <= total_vertices; ++i)
//            {
//                sub_sub_str = split.string_split(sub_str.at((unsigned long)i), '/');
//                new_face->vertix_indices.push_back(std::stoi(sub_sub_str.at(0))-1);
//            }
//
//            for(int v = 0; v < (new_face->vertix_indices.size()); v++)
//            {
//                auto side_indices = new int[4];
//
//                side_indices[0] = new_face->vertix_indices[v];
//                side_indices[1] = new_face->vertix_indices[v+1];
//                side_indices[2] = -1;
//                side_indices[3] = -1;
//
//                if((v + 1) >= new_face->vertix_indices.size())
//                {
//                    side_indices[1] = new_face->vertix_indices[0];
//                }
//
//                new_face->edges.push_back(side_indices);
//            }
//            this->faces.push_back(*new_face);
//
//            if(verbose)
//            {
//                std::cout << "Line " <<
//                          counter << ": " <<
//                          line << "\n";
//            }
//        }
//        else
//        {
//            if(verbose)
//            {
//                std::cout << "Line " << counter << ": " << line << "\n";
//            }
//        }
//    }
//    file.close();
//
//    if(verbose)
//    {
//        std::cout << "================================================================================ \n\n" ;
//    }
//
//    this->UpdateConnections();
//}
//
//
//
//
//// ****************************************************************************
////
//// ****************************************************************************
//void meshio::SurfaceMesh::ExportObj(std::string const& filename, bool verbose)
//{
//    std::ofstream file;
//    file.open(filename);
//
//    if(!file.is_open())
//    {
//        std::cout << "Error creating file " << filename << "\n";
//    }
//    else
//    {
//        if(verbose)
//        {
//            std::cout << "File " << filename << "created successfully." << "\n";
//        }
//    }
//
//    if(verbose)
//    {
//        std::cout << "Outputting information below:" << "\n\n";
//        std::cout << "================================================================================ \n" ;
//    }
//
//    file << "# \n";
//    file << "# Exported Mesh File. \n";
//    file << "# \n";
//    file << "o Plane \n";
//
//    std::vector<meshio::Vertex>::iterator ivertex;
//    for (ivertex = this->vertices.begin(); ivertex != this->vertices.end(); ivertex++)
//    {
//        file << "v " <<
//        std::fixed << std::setprecision(6) <<
//        ivertex->xComp << " " <<
//        ivertex->yComp << " " <<
//        ivertex->zComp << "\n";
//
//        if(verbose)
//        {
//            std::cout << "v " <<
//            ivertex->xComp << " " <<
//            ivertex->yComp << " " <<
//            ivertex->zComp << "\n";
//        }
//    }
//
//    if(!faces.empty())
//    {
//        meshio::Face first_face = this->faces.front();
//
//        file << "vn " <<
//        first_face.geometric_normal.xComp << " " <<
//        first_face.geometric_normal.yComp << " " <<
//        first_face.geometric_normal.zComp << "\n";
//
//        file << "# \n";
//        file << "s off \n";
//
//        if(verbose)
//        {
//            std::cout << "vn " <<
//            first_face.geometric_normal.xComp << " " <<
//            first_face.geometric_normal.yComp << " " <<
//            first_face.geometric_normal.zComp << "\n";
//        }
//
//        std::vector<meshio::Face>::iterator iface;
//        for (iface = this->faces.begin(); iface != this->faces.end(); iface++)
//        {
//            file << "f " <<
//                 iface->vertix_indices[0]+1 << "//1 " <<
//                 iface->vertix_indices[1]+1 << "//1 " <<
//                 iface->vertix_indices[2]+1 << "//1 \n";
//
//            if(verbose)
//            {
//                std::cout << "f " <<
//                iface->vertix_indices[0]+1 << "//1 " <<
//                iface->vertix_indices[1]+1 << "//1 " <<
//                iface->vertix_indices[2]+1 << "//1 \n";
//            }
//        }
//    }
//
//    file.close();
//
//    if(verbose)
//    {
//        std::cout << "================================================================================ \n" ;
//    }
//
//    std::cout << "Finished exporting " << filename << ". \n";
//}
