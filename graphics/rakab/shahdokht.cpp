#include "shahdokht.h"

ShahDokht::ShahDokht(QWidget *parent)
    : PurpleCard(1, "ShahDokht", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to ShahDokht if needed
    faceURL =  ":/new/cards/banafsh/assets/cards/banafsh/Shah_Dokht.png";
}

std::string ShahDokht::getName() const
{
    return name;
}

std::string ShahDokht::getType() const
{
    return type;
}

int ShahDokht::getNumberOnTheCard() const
{
    return numberOnTheCard;
}

int ShahDokht::getPoints() const
{
    return points;
}

void ShahDokht::setPoints(int pointsVal)
{
    points = pointsVal;
}
