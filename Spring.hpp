#ifndef SPRING_HPP
#define SPRING_HPP

#include "Season.hpp"
#include "Game.hpp"

class Spring : public Season
{
public:
    Spring();
    virtual void startEffect(Game &) override;
    virtual void endEffect(Game &) override;
    virtual void refresh(Game &) override;
    virtual std::string getName() const override;
    virtual std::string getType() const override;
    virtual int getNumerOnTheCard() const override;
    virtual int getPoints() const override;
    virtual void setPoints(int) override;

private:
};
#endif