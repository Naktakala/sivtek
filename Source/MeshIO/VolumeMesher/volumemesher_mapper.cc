#include "volumemesher.h"



int meshio::VolumeMesher::MapNode(int ireference)
{
    if(this->node_ordering.empty())
    {
        return ireference;
    }

    meshio::NodeIndexMap* mapping;

    try
    {
        mapping = this->node_ordering.at((unsigned long)ireference);
    }
    catch(std::out_of_range &o)
    {
        std::cerr << "ERROR: Cannot reference node mapping...";
        exit(EXIT_FAILURE);
    }

    return mapping->mapped_to;
}

int meshio::VolumeMesher::ReverseMapNode(int i)
{
    if(this->reverse_node_ordering.empty())
    {
        return i;
    }

    return reverse_node_ordering[i];
}
