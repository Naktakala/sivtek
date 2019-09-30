#include "surfacemesh.h"

void meshio::SurfaceMesh::UpdateConnections()
{
    //std::vector<meshio::Face>::iterator current_face;
//
    //for(current_face = this->faces.begin(); current_face != this->faces.end(); current_face++)
    //{
    //    int outer_index = (int)std::distance(this->faces.begin(), current_face);
//
    //    for(int e = 0; e < 3; e++)
    //    {
    //        current_face->edge_indeces[e][2] = -1;
    //        current_face->edge_indeces[e][3] = -1;
    //    }
//
    //    std::vector<meshio::Face>::iterator other_face;
    //    for(other_face = faces.begin(); other_face != faces.end(); other_face++)
    //    {
    //        int inner_index = (int)std::distance(this->faces.begin(), other_face);
    //        for(int e = 0; e < 3; e++)
    //        {
    //            for(int e2 = 0; e2 < 3; e2++)
    //            {
    //                if((current_face->edge_indeces[e][0] == other_face->edge_indeces[e2][1]) &&
    //                   (current_face->edge_indeces[e][1] == other_face->edge_indeces[e2][0]))
    //                {
    //                    current_face->edge_indeces[e][2] = inner_index;
    //                    current_face->edge_indeces[e][3] = e2;
    //                }
    //            }
    //        }
    //    }
    //}

    for(int f = 0; f < this->faces.size(); f++)
    {
        auto current_face = this->faces[f];

        for(int g = 0; g < this->faces.size(); g++)
        {
            if(f != g)
            {
                auto other_face = this->faces[g];
                for(auto &edge : current_face.edges)
                {
                    for(int i = 0; i < other_face.edges.size(); i++)
                    {
                        if((edge[0] == other_face.edges[i][1]) &&
                           (edge[1] == other_face.edges[i][0]))
                        {
                            edge[2] = g;
                            edge[3] = i;
                        }
                    }
                }
            }
        }
    }
}
