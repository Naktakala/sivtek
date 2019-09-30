#include "silohandler.h"


// ****************************************************************************
//
// ****************************************************************************
void readerio::SiloHandler::ExportSiloTest()
{
    std::string filename = "Test.silo"

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
                7,10,11,8,1,4,5,2, // Shape: Hex
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

    shape_type  = {DB_ZONETYPE_HEX, DB_ZONETYPE_POLYHEDRON};
    shape_count = {1,2};
    shape_size  = {8,53};

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
}


// ****************************************************************************
//
// ****************************************************************************
void readerio::SiloHandler::WriteSiloPDT(const std::string &filename)
{
    std::cout << "Writing" << filename << ". \n";

    //============================================= Creating File
    std::string file_info = "Simple Unstructured Mesh Silo Test File";

    DBfile* dbfile = nullptr;
    dbfile = DBCreate(filename.c_str(), DB_CLOBBER, DB_LOCAL, file_info.c_str(), DB_PDB);


    //============================================= Making Dir
    //std::string sub_dir = "/Test";
    //DBMkDir(dbfile, sub_dir.c_str());
    DBSetDir(dbfile, "/");


    //============================================= Writing Coordinates
    std::vector<double> coordinates_x,coordinates_y,coordinates_z;
    coordinates_x = {-1.0,1.0,-1.0,1.0,-1.0,1.0,-1.0,1.0};
    coordinates_y = {-1.0,1.0,-1.0,1.0,-1.0,1.0,-1.0,1.0};
    coordinates_z = {-1.0,1.0,-1.0,1.0,-1.0,1.0,-1.0,1.0};

    double* coordinates[3];
    coordinates[0] = coordinates_x.data();
    coordinates[1] = coordinates_y.data();
    coordinates[2] = coordinates_z.data();


    //============================================= Init Variables
    int num_dims   = 3;

    int num_nodes  = 8;
    int lnodelist  = 0;

    int num_zones  = 1;
    int num_shapes;

    int origin     = 0;
    int low_off    = 0;
    int high_off   = 0;

    std::vector<int> nodelist;
    std::vector<int> shape_type;
    std::vector<int> shape_size(1,0);
    std::vector<int> shape_count;


    //============================================= Writing Connectivity
    nodelist = {
        6,                 // Shape: Polyhedral Hex
        4,8,7,6,5,
        4,7,3,2,6,
        4,3,4,8,7,
        4,4,8,5,1,
        4,4,3,8,7,
        4,2,1,5,6
        //1,2,3,4,5,6,7,8
    };

    //shape_type  = {DB_ZONETYPE_HEX};
    shape_type  = {DB_ZONETYPE_POLYHEDRON};
    shape_count = {1};
    shape_size[0] = (int)nodelist.size();

    lnodelist  = (int)nodelist.size();
    num_shapes = (int)shape_count.size();


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
                 nullptr                         // Optionlist
    );


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


    //============================================= Closing File
    DBClose(dbfile);
}
