#include "Season.hpp"

#ifndef SPRING_HPP
#define SPRING_HPP

class Spring : public Season
{
public:
    Spring();
    void start(std::vector<Player> &);
    void end(std::vector<Player> &);
private:
};
#endif