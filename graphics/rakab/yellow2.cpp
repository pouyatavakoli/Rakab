#include "yellow2.h"

Yellow2::Yellow2(QWidget *parent)
    : YellowCard(2, "Yellow2", parent)
{
    faceURL = ":/new/cards/zard/assets/cards/zard/002.png";
}

std::string Yellow2::getName() const
{
    return name;
}

std::string Yellow2::getType() const
{
    return type;
}

int Yellow2::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Yellow2::getPoints() const
{
    return points;
}

void Yellow2::setPoints(int pointsVal)
{
    points = pointsVal;
}
