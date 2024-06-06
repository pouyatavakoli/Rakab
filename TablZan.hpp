#ifndef TABLZAN_HPP
#define TABLZAN_HPP

#include "PurpleCard.hpp"
#include "Player.hpp"

class TablZan : public PurpleCard
{
public:
    TablZan();
    void effect(Player &);
private:
};
#endif