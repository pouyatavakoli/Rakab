#ifndef YELLOW10_HPP
#define YELLOW10_HPP

#include "YellowCard.hpp"

class Yellow10 : public YellowCard
{
public:
    Yellow10();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif