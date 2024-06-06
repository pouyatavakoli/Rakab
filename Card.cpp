
#include "Card.hpp"

Card::Card(int numberOnTheCardVal, std::string typeVal, std::string nameVal)
    : name(nameVal), type(typeVal), numberOnTheCard(numberOnTheCardVal)
{
    points = numberOnTheCard;
}

void Card::setPoints(int score)
{
    this->points = score;
}
int Card::getPoints() const
{
    return points;
}
std::string Card::getType() const
{
    return type;
}
int Card::getNumerOnTheCard() const
{
    return numberOnTheCard;
}

std::string Card::getName() const
{
    return name;
}
