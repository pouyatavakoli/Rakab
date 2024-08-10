#include "map.h"

Map::Map()
{
    provinces.push_back("BELLA");
    provinces.push_back("CALINE");
    provinces.push_back("ENNA");
    provinces.push_back("ATELA");
    provinces.push_back("BORGE");
    provinces.push_back("PLADACI");
    provinces.push_back("DISMASE");
    provinces.push_back("MORINA");
    provinces.push_back("OLIVADI");
    provinces.push_back("ROLLO");
    provinces.push_back("TALMONE");
    provinces.push_back("ELINIA");
    provinces.push_back("ARMENTO");
    provinces.push_back("LIA");

    map["BELLA"] = {"PLADACI", "CALINE", "BORGE"};
    map["CALINE"] = {"ENNA", "ATELA", "BORGE", "PLADACI"};
    map["LIA"] = {"BORGE", "CALINE", "DIMASE", "ATELA"}; //fixed
    map["ATELA"] = {"CALINE", "ENNA", "DISAME"};
    map["BORGE"] = {"ENNA", "CALINE", "DIMASE", "PLADACI", "MORINA", "OLIVADI", "BELLA"};
    map["PLADACI"] = {"BELLA", "BORGE", "MORINA", "ROLLO", "CALINE"};
    map["DISMASE"] = {"ATELA", "ENNA", "BORGE", "OLIVADI"};
    map["MORINA"] = {"PLADACI", "BORGE", "ROLLO", "TALMONE", "OLIVADI", "ARMENTO"};
    map["OLIVADI"] = {"DIMASE", "MORINA", "ARMENTO", "LIA"};
    map["ROLLO"] = {"PLADACI", "TALMONE", "MORINA", "ELINIA"};
    map["TALMONE"] = {"MORINA", "ROLLO", "ELINIA", "ARMENTO"};
    map["ELINIA"] = {"ROLLO", "TALMONE"};
    map["ARMENTO"] = {"LIA", "OLIVADI", "MORINA", "TALMONE"};
    map["ENNA"] = {"OLIVADI", "ARMENTO"}; //fixed
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

bool Map::findProvince(const std::string provinceName) const
{
    for (const auto &province : provinces)
    {
        if (province == provinceName)
        {
            return true;
        }
    }

    return 0;
}
