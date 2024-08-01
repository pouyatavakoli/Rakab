#include "spring.h"

Spring::Spring(QWidget *parent)
    : Season(0, "Spring", parent) // Initialize Season with default values
{
    // Additional initialization specific to Spring if needed
    faceURL = ":/new/cards/banafsh/assets/cards/banafsh/Bahar.png";
}

std::string Spring::getName() const
{
    return name;
}

std::string Spring::getType() const
{
    return type;
}

int Spring::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int Spring::getPoints() const
{
    return points;
}

void Spring::setPoints(int pointsVal)
{
    points = pointsVal;
}
