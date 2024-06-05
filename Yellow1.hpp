#include "YellowCard.hpp"

#ifndef YELLOW1_HPP
#define YELLOW1_HPP
class Yellow1 : public YellowCard
{
public:
    Yellow1();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;

private:
};
#endif