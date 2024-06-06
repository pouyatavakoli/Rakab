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

private:
};
#endif