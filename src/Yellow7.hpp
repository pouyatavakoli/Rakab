#ifndef YELLOW7_HPP
#define YELLOW7_HPP

#include "YellowCard.hpp"

class Yellow7 : public YellowCard
{
public:
    Yellow7();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif