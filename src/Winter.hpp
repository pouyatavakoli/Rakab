#ifndef WINTER_HPP
#define WINTER_HPP

#include "Season.hpp"

class Winter : public Season
{
public:
    Winter();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;

private:
};
#endif