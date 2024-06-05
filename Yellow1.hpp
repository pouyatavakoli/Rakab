
#include "YellowCard.hpp"
#ifndef YELLOW1_HPP
#define YELLOW1_HPP
class Yellow1 : public YellowCard
{
public:
    Yellow1();
    void play() override
    {
        std::cout << "playing yellow1";
    }
};
#endif