#ifndef WINTER_HPP
#define WINTER_HPP

#include "Season.hpp"

class Winter : public Season
{
public:
    Winter();
    virtual void startEffect(std::vector<Player> &) override;
    virtual void endEffect(std::vector<Player> &) override;
    virtual void refresh(std::vector<Player> &) override;

private:
};
#endif