#include <unordered_map>
#include <iostream>
#include <vector>

#ifndef MAP_HPP
#define MAP_HPP
class Map
{
public:
    Map();
    // Function to get adjacent provinces
    const std::vector<std::string> &get_adjacent_provinces(const std::string &key);
    bool findProvince(const std::string) const;

private:
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::vector<std::string> provinces;
};

#endif