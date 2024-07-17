#ifndef YELLOW6_HPP
#define YELLOW6_HPP

#include "YellowCard.hpp"

class Yellow6 : public YellowCard
{
public:
    Yellow6();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif