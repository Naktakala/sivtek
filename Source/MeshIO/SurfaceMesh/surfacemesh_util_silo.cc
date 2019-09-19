#include "surfacemesh.h"
#include "../Cell/cell.h"

#include <iostream>
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

    while(shape_count < this->total_shapes)
    {
        auto* new_cell = new meshio::Cell;

        curloc++;
        number_faces = this->node_index.at((unsigned long)curloc);

        for(int f = 0; f < number_faces; f++)
        {
            curloc++;
            number_verts = this->node_index.at((unsigned long)curloc);

            auto new_face = new meshio::Face;

            for(int v = 0; v < number_verts; v++)
            {
                curloc++;
                new_face->face_nodes.push_back(this->node_index.at((unsigned long)curloc));
            }

            new_cell->faces.push_back(new_face);
        }

        cells.push_back(new_cell);
        shape_count++;
    }

}