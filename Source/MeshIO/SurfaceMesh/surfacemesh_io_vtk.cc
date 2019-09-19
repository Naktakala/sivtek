#include "surfacemesh.h"
#include "../Cell/cell.h"
#include "../Cell/cell_polygon.h"

#include <iostream>
#include <string>

#include <vtkCellType.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkUnstructuredGridWriter.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkXMLPUnstructuredGridWriter.h>

#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkPointData.h>
#include <vtkFieldData.h>
#include <vtkDoubleArray.h>
#include <vtkIntArray.h>
#include <vtkStringArray.h>

#include <vtkInformation.h>


extern std::vector<meshio::MeshHandler*> meshhandler_stack;


// ****************************************************************************
//
// ****************************************************************************
void meshio::SurfaceMesh::ImportVTK(std::string const &filename, bool verbose)
{}




// ****************************************************************************
//
// ****************************************************************************
void meshio::SurfaceMesh::ExportVTK(std::string const &filename, bool verbose)
{
    if(verbose)
    {
        std::cout << "\n==================================================" << std::endl;
        std::cout << "Commencing VTK Export." << std::endl;
    }

    //============================================= Dumping Vertices
    if(verbose){std::cout << "Dumping Vertex." << std::endl;}

    std::vector<std::vector<double>> d_nodes;

    auto points = vtkSmartPointer<vtkPoints>::New();

    for(int v = 0; v < nodes.size(); v++)
    {
        std::vector<double> d_node;
        d_node.push_back(nodes[v].xComp);
        d_node.push_back(nodes[v].zComp);
        d_node.push_back(nodes[v].zComp);

        d_nodes.push_back(d_node);

        points->InsertPoint(v, d_node.data());
    }

    if(verbose){std::cout << "Finishing Vertex Dump." << std::endl;}

    //============================================= Init grid and material name

    if(verbose){std::cout << "Creating Grids." << std::endl;}

    vtkUnstructuredGrid* ugrid;
    ugrid = vtkUnstructuredGrid::New();
    ugrid->SetPoints(points);

    if(verbose){std::cout << "Finishing Grids." << std::endl;}

    //============================================= Populating Cell info
    if(verbose){std::cout << "Populating Cell Info" << std::endl;}

    int number_cells = (int)node_index.size();
    for(int c = 0; c < number_cells; c++)
    {
        int cell_node = node_index[c];
        auto cell = cells[cell_node];

        auto poly_cell = (meshio::CellPolygon*)cell;
        int num_verts = (int)poly_cell->vertex_indices.size();

        if(verbose){std::cout << "Moving vertex:  " << c << " from cell: " << v << std::endl;}

        std::vector<vtkIdType > cell_info((unsigned long)num_verts);

        for(int v = 0; v < num_verts; v++)
        {
            if(verbose){std::cout << "Moving vertex:  " << v << " from cell: " << c << std::endl;}
            cell_info[v] = poly_cell->vertex_indices[v];
        }

        vtkSmartPointer<vtkCellArray> faces = vtkSmartPointer<vtkCellArray>::New();

        int num_faces = (int)cell->faces.size();
        for(int f = 0; f < num_faces; f++)
        {
            if(verbose){std::cout << "Moving face:  " << f << " from cell: " << c << std::endl;}
            int num_fverts = (int)poly_cell->faces[f]->vertix_indices.size();
            std::vector<vtkIdType> face((unsigned long)num_fverts);
            for(int fv = 0; fv < num_fverts; fv++)
            {
                face[fv] = poly_cell->faces[f]->vertix_indices[fv];

                faces->InsertNextCell(num_fverts, face.data());
            }
        }

        ugrid->InsertNextCell(VTK_POLYHEDRON, num_verts, cell_info.data(), num_faces, faces->GetPointer());
    }

    if(verbose)
    {
        std::cout << "Finished Grids." << std::endl;
    }

    //============================================= Creating Filename
    std::string base = "test";
    std::string ext = ".vtu";
    std::string name = std::string(base);
    std::string fname = name + ext;

    vtkXMLUnstructuredGridWriter* grid_writer = vtkXMLUnstructuredGridWriter::New();

    grid_writer->SetInputData(ugrid);
    grid_writer->SetFileName(fname.c_str());

    grid_writer->Write();

    //============================================= Verbose Commands
    if(verbose){std::cout << "==================================================" << std::endl;}

}