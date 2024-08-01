#include "yellow5.h"

Yellow5::Yellow5(QWidget *parent)
    : YellowCard(5, "Yellow5", parent)
{
    faceURL = ":/new/cards/zard/assets/cards/zard/005.png";
}

std::string Yellow5::getName() const
{
    return name;
}

std::string Yellow5::getType() const
{
    return type;
}

int Yellow5::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow5::getPoints() const
{
    return points;
}

void Yellow5::setPoints(int pointsVal)
{
    points = pointsVal;
}
