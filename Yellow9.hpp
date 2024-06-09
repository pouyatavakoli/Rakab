#ifndef YELLOW9_HPP
#define YELLOW9_HPP

#include "YellowCard.hpp"

class Yellow9 : public YellowCard
{
public:
    Yellow9();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;
};
#endif