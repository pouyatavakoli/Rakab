#include "PurpleCard.hpp"
#include "player.hpp"

#ifndef MATARSAK_HPP
#define MATARSAK_HPP

class Matarsak : public PurpleCard
{
public:
    Matarsak();
    void effect(Player &);

private:
};
#endif