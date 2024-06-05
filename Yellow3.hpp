#include "YellowCard.hpp"

#ifndef YELLOW3_HPP
#define YELLOW3_HPP
class Yellow3 : public YellowCard
{
public:
    Yellow3();
    virtual int get_score() const;
    virtual int getOriginalScore() const override;
    virtual std::string getType() const override;

private:
};
#endif