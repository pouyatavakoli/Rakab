#include "Season.hpp"
#ifndef WINTER_HPP
#define WINTER_HPP

class Winter : public Season
{
public:
    Winter();
    void start(Player);
    void end(Player);

private:
};
#endif