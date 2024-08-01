#include "yellow4.h"

Yellow4::Yellow4(QWidget *parent)
    : YellowCard(4, "Yellow4", parent)
{
    faceURL = ":/new/cards/zard/assets/cards/zard/004.png";
}

std::string Yellow4::getName() const
{
    return name;
}

std::string Yellow4::getType() const
{
    return type;
}

int Yellow4::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow4::getPoints() const
{
    return points;
}

void Yellow4::setPoints(int pointsVal)
{
    points = pointsVal;
}

