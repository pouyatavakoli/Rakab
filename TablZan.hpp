#include "PurpleCard.hpp"
#include "Player.hpp"

#ifndef TABLZAN_HPP
#define TABLZAN_HPP

class TablZan : public PurpleCard
{
public:
    TablZan();
    void effect(Player &);
private:
};
#endif