#ifndef YELLOW3_HPP
#define YELLOW3_HPP

#include "YellowCard.hpp"

class Yellow3 : public YellowCard
{
public:
    Yellow3();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif