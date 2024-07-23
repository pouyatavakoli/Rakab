#ifndef MAP_H
#define MAP_H

#include <unordered_map>
#include <iostream>
#include <vector>

class Map
{
public:
    Map();
    const std::vector<std::string> &get_adjacent_provinces(const std::string &key);
    bool findProvince(const std::string) const;

private:
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::vector<std::string> provinces;
};

#endif // MAP_H
