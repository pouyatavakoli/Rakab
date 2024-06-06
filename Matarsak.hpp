#ifndef MATARSAK_HPP
#define MATARSAK_HPP

#include "PurpleCard.hpp"
#include "Player.hpp"

class Matarsak : public PurpleCard
{
public:
    Matarsak();
    void effect(Player &);

private:
};
#endif