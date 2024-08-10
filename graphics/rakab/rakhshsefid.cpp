#include "rakhshsefid.h"

RakhshSefid::RakhshSefid(QWidget *parent)
    : PurpleCard(0, "RakhshSefid", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to RakhshSefid if needed
    faceURL = ":/new/cards/banafsh/assets/cards/banafsh/Rakhsh_Sefid.png";
}

void RakhshSefid::startEffect()
{
    // Implement start effect for RakhshSefid
}

void RakhshSefid::endEffect()
{
    // Implement end effect for RakhshSefid
}

std::string RakhshSefid::getName() const
{
    return name;
}

std::string RakhshSefid::getType() const
{
    return type;
}

int RakhshSefid::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int RakhshSefid::getPoints() const
{
    return points;
}

void RakhshSefid::setPoints(int pointsVal)
{
    points = pointsVal;
}
