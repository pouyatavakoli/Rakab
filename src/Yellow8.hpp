#ifndef YELLOW8_HPP
#define YELLOW8_HPP

#include "YellowCard.hpp"

class Yellow8 : public YellowCard
{
public:
    Yellow8();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif