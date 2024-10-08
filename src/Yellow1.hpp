#ifndef YELLOW1_HPP
#define YELLOW1_HPP

#include "YellowCard.hpp"
class Yellow1 : public YellowCard
{
public:
    Yellow1();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override ;
};
#endif