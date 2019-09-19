#include "volumemesher.h"



void meshio::VolumeMesher::CreateTriangleCells()
{
    //std::vector<meshio::Face>::iterator face;
    //for(face = surface_mesh->faces.begin(); face != surface_mesh->faces.end(); face++)
    //{
    //    auto cell = new meshio::CellTriangle;
//
    //    for(int k = 0; k < 3; k++)
    //    {
    //        cell->vertix_index[k] = face->vertix_indices[k];
    //        cell->normal_index[k] = face->normal_indices[k];
    //        cell->edge_index[k][0] = face->edge_indeces[k][0];
    //        cell->edge_index[k][1] = face->edge_indeces[k][1];
    //        cell->edge_index[k][2] = face->edge_indeces[k][2];
    //        cell->edge_index[k][3] = face->edge_indeces[k][3];
//
    //        cell->centroid = cell->centroid + surface_mesh->vertices[cell->vertix_index[k]];
    //    }
//
    //    cell->centroid = cell->centroid/3;
    //    cell->cell_global_id = (int)volume_continuum->cells.size();
    //    volume_continuum->cells.push_back(cell);
    //}
}


void meshio::VolumeMesher::GetBoundaryCells()
{

}
