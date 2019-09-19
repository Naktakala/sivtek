#ifndef _READERIO_SILOHANDLER_
#define _READERIO_SILOHANDLER_

//#include "../../ReaderIO/readerio.h"

#include <string>
#include <vector>
#include <iostream>

#include "silo.h"

class readerio::SiloHandler
{
public:
    std::vector<readerio::MeshUCD> ucdmeshes;

public:
    // silohandler_reader
    void      LoadSilo(const std::string &filename, int driver_type, int read_mode);

    // silohandler_writer
    void      WriteSilo(const std::string &filename);
    void      WriteSiloPDT(const std::string &filename);

    // silohandler_utilities
    void      PrintContents(DBfile* dbfile);
    void      ReadUCDMesh(DBfile *dbfile);
};

#endif