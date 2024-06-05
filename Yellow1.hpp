#include "YellowCard.hpp"

#ifndef YELLOW1_HPP
#define YELLOW1_HPP
class Yellow1 : public YellowCard
{
public:
    Yellow1();
    virtual int get_score() const;
    int getOriginalScore() const;

private:
    const int originalScore{1};
};
#endif