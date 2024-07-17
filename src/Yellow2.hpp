#ifndef YELLOW2_HPP
#define YELLOW2_HPP

#include "YellowCard.hpp"

class Yellow2 : public YellowCard
{
public:
    Yellow2();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif