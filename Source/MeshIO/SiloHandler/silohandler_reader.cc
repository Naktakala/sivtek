#include "silohandler.h"

#include <iomanip>


// ****************************************************************************
//
// ****************************************************************************
void readerio::SiloHandler::LoadSilo(const std::string &filename, int driver_type, int read_mode)
{

    //std::cout << "\n" << "Loading SiloHandler file " << filename << "\n";

    DBfile* silo_file = DBOpen(filename.c_str(), driver_type, read_mode);
    std::cout << "\n" << "Loading SiloHandler file: " << filename << (silo_file == nullptr ? " failed!\n" : " succeeded! \n\n");

    DBSetDir(silo_file, "/");
    ReadUCDMesh(silo_file);

    DBClose(silo_file);
}


// ****************************************************************************
//
// ****************************************************************************
void readerio::SiloHandler::ReadUCDMesh(DBfile* dbfile)
{
    double* x = nullptr;
    double* y = nullptr;
    double* z = nullptr;
    double rcoord[3];

    DBtoc* table_contents = DBGetToc(dbfile);
    //std::cout << "\n" << table_contents->ucdmesh_names[0] << "\n";

    DBucdmesh* umesh = nullptr;

    umesh = DBGetUcdmesh(dbfile, table_contents->ucdmesh_names[0]);
    if(umesh == nullptr)
    {
        umesh = DBAllocUcdmesh();
        std::cout << "UCDMesh received nullptr. \n";
    }

    auto* new_ucdmesh = new readerio::MeshUCD;

    if(umesh->datatype == DB_DOUBLE)
    {
        auto xcoord = (double*)umesh->coords[0];
        auto ycoord = (double*)umesh->coords[1];
        auto zcoord = (double*)umesh->coords[2];

        for(int i = 0; i < umesh->nnodes; i++)
        {
            new_ucdmesh->coordinates[0] = xcoord[i];
            new_ucdmesh->coordinates[1] = ycoord[i];
            new_ucdmesh->coordinates[2] = zcoord[i];
            this->ucdmeshes.push_back(*new_ucdmesh);

            std::cout << std::fixed << std::setprecision(5)
                      << " " << xcoord[i]
                      << " " << ycoord[i]
                      << " " << zcoord[i]<< "\n";
        }
    }



}




