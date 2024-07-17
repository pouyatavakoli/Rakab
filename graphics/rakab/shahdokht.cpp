#include "shahDokht.h"

ShahDokht::ShahDokht(QObject *parent)
    : PurpleCard(1, "ShahDokht", parent) // Initialize PurpleCard with default values
{
    // Additional initialization specific to ShahDokht if needed
}

QString ShahDokht::getName() const
{
    return name;
}

QString ShahDokht::getType() const
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
