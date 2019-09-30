#include "silohandler.h"


void readerio::SiloHandler::PrintContents(DBfile* dbfile)
{
    DBtoc* table_contents = DBGetToc(dbfile);

    std::cout << "\n" << "Dumping Table of Contents: \n"
              << "    " << "ncurve: "           << table_contents->ncurve           << "\n"
              << "    " << "ncsgmesh: "         << table_contents->ncsgmesh         << "\n"
              << "    " << "ncsgvar: "          << table_contents->ncsgvar          << "\n"
              << "    " << "ndefvars: "         << table_contents->ndefvars         << "\n"
              << "    " << "nmultimesh: "       << table_contents->nmultimesh       << "\n"
              << "    " << "nmultimeshadj: "    << table_contents->nmultimeshadj    << "\n"
              << "    " << "nmultivar: "        << table_contents->nmultivar        << "\n"
              << "    " << "nmultimat: "        << table_contents->nmultimat        << "\n"
              << "    " << "nmultimatspecies: " << table_contents->nmultimatspecies << "\n"
              << "    " << "nqmesh: "           << table_contents->nqmesh           << "\n"
              << "    " << "nqvar: "            << table_contents->nqvar            << "\n"
              << "    " << "nucdmesh: "         << table_contents->nucdmesh         << "\n"
              << "    " << "nucdvar: "          << table_contents->nucdvar          << "\n"
              << "    " << "nptmesh: "          << table_contents->nptmesh          << "\n"
              << "    " << "nptvar: "           << table_contents->nptvar           << "\n"
              << "    " << "nvar: "             << table_contents->nvar             << "\n"
              << "    " << "nmat: "             << table_contents->nmat             << "\n"
              << "    " << "nobj: "             << table_contents->nobj             << "\n"
              << "    " << "ndir: "             << table_contents->ndir             << "\n"
              << "    " << "nmrgtree: "         << table_contents->nmrgtree         << "\n"
              << "    " << "ngroupelmap: "      << table_contents->ngroupelmap      << "\n"
              << "    " << "nmrgvar: "          << table_contents->nmrgvar          << "\n"
              << "    " << "narray: "           << table_contents->narray           << "\n"
              << "\n";

    //table_contents->ucdmesh_names;
}
