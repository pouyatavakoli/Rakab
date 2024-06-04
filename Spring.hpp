#include "Season.hpp"

#ifndef SPRING_HPP
#define SPRING_HPP

class Spring : public Season
{
public:
    Spring();
    void start(Player);
    void end(Player);
private:
};
#endif