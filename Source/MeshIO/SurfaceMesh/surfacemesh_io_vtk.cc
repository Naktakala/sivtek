#include "surfacemesh.h"

#include "../Cell/cell.h"
#include "../Cell/cell_polygon.h"
#include "../Cell/cell_polyhedron.h"


#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkUnstructuredGridWriter.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkXMLPUnstructuredGridWriter.h>

#include <vtkCellArray.h>
#include <vtkCellData.h>

#include <vtkInformation.h>
#include <vtkIntArray.h>



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
        d_node.push_back(nodes[v]->xComp);
        d_node.push_back(nodes[v]->yComp);
        d_node.push_back(nodes[v]->zComp);

        d_nodes.push_back(d_node);

        points->InsertPoint(v, d_node.data());
    }

    if(verbose){std::cout << "Finishing Vertex Dump." << std::endl;}

    //============================================= Init grid and material name

    if(verbose){std::cout << "Creating Grids." << std::endl;}

    vtkUnstructuredGrid* ugrid;
    vtkIntArray*         material_array;

    ugrid           = vtkUnstructuredGrid::New();
    material_array  = vtkIntArray::New();

    material_array->SetName("Material");
    ugrid->SetPoints(points);

    if(verbose){std::cout << "Finishing Grids." << std::endl;}

    //============================================= Populating Cell info
    if(verbose){std::cout << "Populating Cell Info" << std::endl;}

    int number_cells = (int)cells.size();
    //int number_cells = 1;

    if(verbose){std::cout << "Total Cells: " << number_cells << std::endl;}

    for(int c = 0; c < number_cells; c++)
    {
       // int cell_node = node_index[c];
        auto cell = cells[c];

        //============================================= Polyhedra
        if(cell->Type() == meshio::CellType::POLYHEDRON)
        {
            auto poly_cell = (meshio::CellPolyhedron*)cell;
            //int material_id = cell->material_id;

            //============================================= Cell Info
            int num_verts = (int)poly_cell->vertex_indices.size();
            std::vector<vtkIdType> cell_info((unsigned long) num_verts);

            for(int v = 0; v < num_verts; v++)
            {
                if(verbose){std::cout << "Moving vertex:  " << v << " from cell: " << c << std::endl;}

                cell_info[v] = poly_cell->vertex_indices[v];
            }

            vtkSmartPointer<vtkCellArray> faces = vtkSmartPointer<vtkCellArray>::New();

            int num_faces = (int)poly_cell->faces.size();
            for(int f = 0; f < num_faces; f++)
            {
                if(verbose){std::cout << "Moving face:  " << f + 1 << " from cell: " << c + 1 << std::endl;}

                int num_fverts = (int)poly_cell->faces[f]->vertix_indices.size();
                std::vector<vtkIdType> face((unsigned long) num_fverts);

                for(int fv = 0; fv < num_fverts; fv++)
                {
                    face[fv] = poly_cell->faces[f]->vertix_indices[fv];
                }

                faces->InsertNextCell(num_fverts, face.data());
            }
            ugrid->InsertNextCell(VTK_POLYHEDRON, num_verts, cell_info.data(), num_faces, faces->GetPointer());
            //material_array->InsertNextValue(material_id);
        }//Polyhedra


        //============================================= Polygon
        if(cell->Type() == meshio::CellType::POLYGON)
        {
            std::cout << "Am I a polygon?" << std::endl;

            auto poly_cell = (meshio::CellPolygon*)cell;

            //============================================= Cell Info
            std::vector<vtkIdType> cell_info;
            int  num_verts = (int) poly_cell->vertex_indices.size();

            for(int v = 0; v < num_verts; v++)
            {
                if(verbose)
                {
                    std::cout << "Moving vertex:  " << v << " from cell: " << c << std::endl;
                }
                cell_info.push_back(poly_cell->vertex_indices[v]);
            }

            ugrid->InsertNextCell(VTK_POLYGON, num_verts, cell_info.data());
            //material_array->InsertNextValue(material_id);
        }//Polygon
    }


    //============================================= Verbose Output
    if(verbose)
    {
        std::cout << "Finished Populating Cell Info." << std::endl;
    }

    //============================================= Creating Filename
    //std::string base = filename;
    std::string ext = ".vtu";
    std::string name = std::string(filename);
    std::string fname = name + ext;

    vtkXMLUnstructuredGridWriter* grid_writer = vtkXMLUnstructuredGridWriter::New();

    grid_writer->SetInputData(ugrid);
    grid_writer->SetFileName(fname.c_str());

    grid_writer->Write();

    //============================================= Verbose Commands
    if(verbose){std::cout << "==================================================" << std::endl;}

}