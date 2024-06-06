#ifndef PARCHAMDAR_HPP
#define PARCHAMDAR_HPP

#include "PurpleCard.hpp"

class ParchamDar : public PurpleCard
{
public:
    ParchamDar();
    // bool ParchamAndBadkhahet(); // It ends the game so inout should br Game type(probably!!!)

    virtual void startEffect() override;
    virtual void endEffect() override;

private:
};
#endif