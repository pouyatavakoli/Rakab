#ifndef YELLOW4_HPP
#define YELLOW4_HPP

#include "YellowCard.hpp"

class Yellow4 : public YellowCard
{
public:
    Yellow4();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif