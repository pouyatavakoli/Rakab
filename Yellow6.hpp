#include "YellowCard.hpp"

#ifndef YELLOW6_HPP
#define YELLOW6_HPP
class Yellow6 : public YellowCard
{
public:
    Yellow6();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
private:
};
#endif