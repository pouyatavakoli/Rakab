#ifndef PARCHAMDAR_HPP
#define PARCHAMDAR_HPP

#include "PurpleCard.hpp"

class ParchamDar : public PurpleCard
{
public:
    ParchamDar();
    // bool ParchamAndBadkhahet(); // It ends the game so inout should br Game type(probably!!!)
    virtual std::string getName() const;
    virtual std::string getType() const;

private:
};
#endif