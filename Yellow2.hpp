#include "YellowCard.hpp"

#ifndef YELLOW2_HPP
#define YELLOW2_HPP
class Yellow2 : public YellowCard
{
public:
    Yellow2();
    virtual int get_score() const;
    int getOriginalScore() const;

private:
const int originalScore{2};
};
#endif // YELLOW2_HPP