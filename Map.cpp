#include "Map.hpp"

Map::Map()
{
    map["BELLA"] = {"PLADACI", "CALINE"};
    map["CALINE"] = {"ENNA", "ATELA", "BORGE"};
    map["ENNA"] = {"BORGE", "CALINE", "DIMASE", "ATELA"};
    map["ATELA"] = {"CALINE","ENNA","DISAME"};
    map["BORGE"] = {"ENNA", "CALINE", "DIMASE","PALADACI","MORINA","OLIVADI"};
    map["PALADACI"] = {"BELLA","BORGE","MORINA","ROLLO"};
    map["DISMASE"] = {"ATELA" , "ENNA" ,"BORGE","OLIVADI"};
    map["MORINA"] = {"PALADACI" ,"BORGE" , "ROLLO" , "TALMONE" ,"OLIVADI" , "ARMENTO"};
    map["OLIVADI"] = {"DIMASE","MORINA","ARMENTO" ,"LIA"};
    map["ROLLO"] = {"PLADACI","TALMONE","MORINA","ELINIA"};
    map["TALMONE"] = {"MORINA","ROLLO","ELINIA"};
    map["ELINIA"] = {"ROLLO","TALMONE"};
    map["ARMENTO"] = {"LIA" , "OLIVADI","MORINA"};
    map["LIA"] = {"OLIVADI" , "ARMENTO"};

}

const std::vector<std::string> &Map::get_adjacent_provinces(const std::string &key)
{
    static const std::vector<std::string> empty;
    auto it = map.find(key);
    if (it != map.end())
    {
        return it->second;
    }
    return empty;
}
