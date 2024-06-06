#ifndef MATARSAK_HPP
#define MATARSAK_HPP

#include "PurpleCard.hpp"
#include "Player.hpp"

class Matarsak : public PurpleCard
{
public:
    Matarsak();
    virtual void startEffect(Player &) override;
    virtual void endEffect(Player &) override;

private:
};
#endif