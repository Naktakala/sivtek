#include <iomanip>

#include "surfacemesh.h"

#include "silo.h"


extern std::vector<meshio::MeshHandler*> meshhandler_stack;


// ****************************************************************************
//
// ****************************************************************************
void meshio::SurfaceMesh::ImportSilo(std::string const &filename, bool verbose)
{
    //============================================= Verbose Commands
    if(verbose)
    {
        std::cout << "\n==================================================" << std::endl;
    }

    //============================================= Opening & Testing file
    DBfile* silo_file = DBOpen(filename.c_str(), DB_PDB, DB_READ);
    std::cout << "Loading SiloHandler file: " << filename << (silo_file == nullptr ? " failed!\n" : " succeeded! \n\n");

    DBSetDir(silo_file, "/");

    //============================================= Reading Silo Table of Contents
    DBtoc* table_contents = DBGetToc(silo_file);
    //std::cout << "\n" << table_contents->ucdmesh_names[0] << "\n";

    //============================================= Creating Empty UCDMesh & Empty Material
    DBucdmesh* umesh = nullptr;
    DBmaterial* umat = nullptr;

    //============================================= Checking to see if Mesh exists in file
    umesh = DBGetUcdmesh(silo_file, table_contents->ucdmesh_names[0]);
    if(umesh == nullptr)
    {
        umesh = DBAllocUcdmesh();
        std::cout << "UCDMesh received nullptr. \n";
    }

    //============================================= Checking to see if Mesh exists in file
    umat = DBGetMaterial(silo_file, table_contents->mat_names[0]);
    if(umat == nullptr)
    {
        umat = DBAllocMaterial();
        std::cout << "Material received nullptr. \n";
    }


    //============================================= Setting Values
    int total_vertices = umesh->nnodes;
    int total_nodes = umesh->zones->lnodelist;
    int mat_id = umat->nmat;
    int total_materials = umat->dims[0];


    std::cout << "Total Nodes: " << total_nodes << std::endl;
    std::cout << "Total Materials IDs: " << mat_id << std::endl;
    std::cout << "Total Materials Nodes: " << total_materials << std::endl;


    //============================================= Information
    if(verbose){std::cout << "\nVertex Information: " << std::endl;}

    if(umesh->datatype == DB_DOUBLE)
    {

        //============================================= Looping through nodes for Vertices
        auto coord_x = (double*)umesh->coords[0];
        auto coord_y = (double*)umesh->coords[1];
        auto coord_z = (double*)umesh->coords[2];

        for(int v = 0; v < total_vertices; v++)
        {
            auto* new_node = new meshio::Node;
            new_node->xComp = coord_x[v];
            new_node->yComp = coord_y[v];
            new_node->zComp = coord_z[v];
            nodes.push_back(new_node);

            //============================================= Verbosity option
            if(verbose)
            {
                std::cout <<
                         "Vertex " <<
                          std::right << std::setw(6) <<
                          v << ":   " <<
                          std::fixed << std::setprecision(5) <<
                          new_node->xComp << "  " <<
                          new_node->yComp << "  " <<
                          new_node->zComp << "  " <<
                          std::endl;
            }
        }
    }

    //============================================= Gathering nodelist
    if(verbose){std::cout << "\n\nNode Information: " << std::endl;}

    for(int n = 0; n < total_nodes; n++)
    {
        auto current_node = umesh->zones->nodelist[n];
        this->node_index.push_back(current_node);

        //============================================= Verbosity option
        if(verbose)
        {
            std::cout <<
                      "Node " <<
                      std::right << std::setw(6) <<
                      n << ":   " <<
                      std::fixed << std::setprecision(5) <<
                      current_node << "  " <<
                      std::endl;
        }
    }

    //============================================= Gathering Material
    if(verbose){std::cout << "\nMaterial Information: " << std::endl;}

    if(umat->datatype == DB_DOUBLE)
    {
        for(int m = 0; m < mat_id; m++)
        {
            auto current_material_id = umat->matnos[m];
            this->mat_index.push_back(current_material_id);

            auto current_material_name = umat->matnames[m];
            this->material_names.push_back(current_material_name);
        }

        for(int ml = 0; ml < total_materials; ml++)
        {
            auto cur_mat = umat->matlist[ml];
            this->material_list.push_back(cur_mat);
        }
    }

    //============================================= Gathering Shape Information
    this->total_shapes = umesh->zones->nshapes;

    for(int st = 0; st < total_shapes; st++)
    {
        //auto current_shape = umesh->zones->shapetype[st];
        //this->shape_types.push_back(current_shape);
        this->shape_types.push_back(30);
    }

    //============================================= Starting Shape Seperation
    this->SeperateShapes();

    //============================================= Closing File
    DBClose(silo_file);

    //============================================= Verbose Commands
    if(verbose){std::cout << "==================================================" << std::endl;}
}




// ****************************************************************************
//
// ****************************************************************************
void meshio::SurfaceMesh::ExportSilo(std::string const &filename, bool verbose)
{}




// ****************************************************************************
//
// ****************************************************************************
void meshio::SurfaceMesh::ExportSiloTest(bool verbose)
{
    std::string filename = "Test.silo";

    //============================================= Verbose Commands
    if(verbose)
    {
        std::cout << "\n==================================================" << std::endl;
        std::cout << "Commencing Silo Export." << std::endl;
    }

    std::cout << "Writing" << filename << ". \n";

    //============================================= Creating File
    std::string file_info = "Simple Unstructured Mesh Silo Test File";

    DBfile* dbfile = nullptr;
    dbfile = DBCreate(filename.c_str(), DB_CLOBBER, DB_LOCAL, file_info.c_str(), DB_PDB);


    //============================================= Mesh Options
    int coord_sys = DB_CARTESIAN;

    DBoptlist* opts = DBMakeOptlist(1);
    DBAddOption(opts, DBOPT_COORDSYS, &coord_sys);


    //============================================= Writing Coordinates
    std::vector<double> coordinates_x,coordinates_y,coordinates_z;
    coordinates_x = {0.0,0.0,1.0,2.0,0.0,1.0,2.0,0.0,1.0,2.0,0.0,1.0,2.0,3.0};
    coordinates_y = {0.0,1.0,1.0,1.0,0.0,0.0,0.0,1.0,1.0,1.0,0.0,0.0,0.0,0.5};
    coordinates_z = {0.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.5};

    double* coordinates[3];
    coordinates[0] = coordinates_x.data();
    coordinates[1] = coordinates_y.data();
    coordinates[2] = coordinates_z.data();


    //============================================= Init Variables
    int num_dims   = 3;

    int num_nodes;
    int lnodelist  = 0;

    int num_zones  = 3;
    int num_shapes;

    int origin     = 0;
    int low_off    = 0;
    int high_off   = 0;

    std::vector<int> nodelist;
    std::vector<int> shape_type;
    std::vector<int> shape_size;
    std::vector<int> shape_count;


    //============================================= Writing Connectivity
    nodelist = {
        //7,10,11,8,1,4,5,2, // Shape: Hex
        6,                 // Shape: Polyhedral Hex
        4,10,11,8,7,
        4,11,5,2,8,
        4,5,4,1,2,
        4,4,10,7,1,
        4,4,5,11,10,
        4,2,1,7,8,
        6,                 // Shape: Polyhedral Hex
        4,11,12,9,8,
        4,12,6,3,9,
        4,6,5,2,3,
        4,5,11,8,2,
        4,5,6,12,11,
        4,3,2,8,9,
        5,                 // Shape:: Polyhedral Tet
        4,3,6,12,9,
        3,6,13,12,
        3,12,13,9,
        3,9,13,3,
        3,3,13,6
    };

    shape_type  = {DB_ZONETYPE_POLYHEDRON,DB_ZONETYPE_POLYHEDRON,DB_ZONETYPE_POLYHEDRON};
    shape_count = {3};
    shape_size  = {84};

    lnodelist  = (int)nodelist.size();
    num_shapes = (int)shape_count.size();
    num_nodes  = (int)coordinates_x.size();


    //============================================= Writing Zone Information
    DBPutZonelist2(dbfile,                       // File
                   "Zones",                      // Zone Name
                   num_zones,                    // Num. of zones
                   num_dims,                     // Num. of dim
                   nodelist.data(),              // Nodelist
                   lnodelist,                    // Nodelist size
                   origin,                       // Origin
                   low_off,                      // Low offset
                   high_off,                     // High offset
                   shape_type.data(),            // Shape types
                   shape_size.data(),            // Shape sizes
                   shape_count.data(),           // Shape count
                   num_shapes,                   // Number of shapes
                   nullptr                       // Optionlist
    );


    //============================================= Writing UCD Mesh
    DBPutUcdmesh(dbfile,                         // File
                 "Mesh",                         // Mesh Name
                 num_dims,                       // Number of dimensions
                 nullptr,                        // Coord. Names
                 coordinates,                    // Coord.
                 num_nodes,                      // Number of nodes
                 num_zones,                      // Number of zones
                 "Zones",                        // Zone name
                 nullptr,                        // Face name
                 DB_DOUBLE,                      // Datatype
                 opts                         // Optionlist
    );


    //============================================= Closing File
    DBClose(dbfile);


    //============================================= Verbose Commands
    if(verbose){std::cout << "==================================================" << std::endl;}
}