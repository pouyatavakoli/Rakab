#ifndef YELLOW5_HPP
#define YELLOW5_HPP

#include "YellowCard.hpp"

class Yellow5 : public YellowCard
{
public:
    Yellow5();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif