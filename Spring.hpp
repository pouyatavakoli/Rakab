#ifndef SPRING_HPP
#define SPRING_HPP

#include "Season.hpp"

class Spring : public Season
{
public:
    Spring();
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;

private:
};
#endif