#ifndef _MESH_MESHFACES_
#define _MESH_MESHFACES_

//#include "meshio.h"

// Struct for Triangles, Quads, and Polygons...
//struct meshio::Face
//{
//    std::vector<int> vertix_indices;
//    std::vector<int> normal_indices;
//    std::vector<int> edge_indeces;
//    std::vector<int*> edges;
//
//    int face_indices[3];
//
//    meshio::Normal geometric_normal;
//    meshio::Normal assigned_normal;
//    meshio::Vertex face_center;
//
//    bool invalidated;
//
//    Face()
//    {
//        for(int k = 0; k < 3; k++)
//        {
//            vertix_indices[k] = -1;
//            normal_indices[k] = -1;
//            edge_indeces[k][0] = -1;
//            edge_indeces[k][1] = -1;
//            edge_indeces[k][2] = -1;
//            edge_indeces[k][3] = -1;
//            invalidated = false;
//        }
//    }
//
//    void SetIndices(int a, int b, int c)
//    {
//        vertix_indices[0] = a;
//        vertix_indices[1] = b;
//        vertix_indices[2] = c;
//
//        edge_indeces[0][0] = a; edge_indeces[0][1] = a;
//        edge_indeces[1][0] = b; edge_indeces[1][1] = b;
//        edge_indeces[2][0] = c; edge_indeces[2][1] = c;
//    }
//
//    void operator=(const Face& that)
//    {
//        for(int k = 0; k < 3; k++)
//        {
//            vertix_indices[k] = that.vertix_indices[k];
//            normal_indices[k] = that.normal_indices[k];
//            edge_indeces[k][0] = that.edge_indeces[k][0];
//            edge_indeces[k][1] = that.edge_indeces[k][1];
//            edge_indeces[k][2] = that.edge_indeces[k][2];
//            edge_indeces[k][3] = that.edge_indeces[k][3];
//        }
//        geometric_normal = that.geometric_normal;
//        geometric_normal = that.geometric_normal;
//        invalidated = that.invalidated;
//
//    }
//
//};

struct meshio::Face
{
    std::vector<int> vertix_indices;
    std::vector<int> normal_indices;
    std::vector<int> edge_indeces;
    std::vector<int*> edges;

    int face_indices[3];

    meshio::Normal geometric_normal;
    meshio::Normal assigned_normal;
    meshio::Vertex face_center;

    bool invalidated;

    Face()
    {
        invalidated = false;
    }

};


struct meshio::PolyFace
{
    std::vector<int> vertix_indices;
    std::vector<int*> edges;
    int face_indices[3];

    meshio::Normal geometric_normal;
    meshio::Vertex face_centroid;

    bool invalidated;

    PolyFace()
    {
        invalidated = false;
    }

};


#endif // MESHFACES_H