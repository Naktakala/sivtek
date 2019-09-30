#include "surfacemesh.h"

#include "../Cell/cell.h"
#include "../Cell/cell_polyhedron.h"

#include <set>
#include <iomanip>

// ****************************************************************************
//
// ****************************************************************************
void meshio::SurfaceMesh::CreateFaces()
{

}


// ****************************************************************************
//
// ****************************************************************************
void meshio::SurfaceMesh::SeperateShapes()
{
    int curloc = -1;
    int shape_count = 0;
    int number_faces = 0;
    int number_verts = 0;

    int stype = (int)shape_types.size();
    std::cout << "\n" << std::endl;
    //for(int s = 0; s < stype; s++)
    //{
    //    std::cout << shape_types[s] << std::endl;
    //}

    //std::cout << shape_types.size() << std::endl;
    while(shape_count < this->total_shapes)
    {
        if(shape_types[shape_count] == 30)
        {
            auto *new_cell = new meshio::CellPolyhedron;

            curloc++;
            number_faces = this->node_index.at((unsigned long) curloc);

            std::set<int> cell_verts;

            for(int f = 0; f < number_faces; f++)
            {
                curloc++;
                number_verts = this->node_index.at((unsigned long) curloc);

                auto new_face = new meshio::PolyFace;

                for(int v = 0; v < number_verts; v++)
                {
                    curloc++;
                    new_face->vertix_indices.push_back(this->node_index.at((unsigned long) curloc));
                    cell_verts.insert(this->node_index.at((unsigned long) curloc));
                }
                new_cell->faces.push_back(new_face);
            }

            for(auto v : cell_verts)
                new_cell->vertex_indices.push_back(v);

            auto temp_mat = this->material_list[shape_count];
            new_cell->material_id = temp_mat;

            cells.push_back(new_cell);
            shape_count++;
        }
    }
}