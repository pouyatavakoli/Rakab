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

private:
    std::unordered_map<std::string, std::vector<std::string>> map;
};

#endif