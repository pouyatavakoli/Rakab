#ifndef TABLZAN_HPP
#define TABLZAN_HPP

#include "PurpleCard.hpp"
#include "Player.hpp"

class TablZan : public PurpleCard
{
public:
    TablZan();
    virtual void startEffect(Player &) override;
    virtual void endEffect(Player &) override;
private:
};
#endif