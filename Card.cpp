
#include "Card.hpp"

Card::Card(int numberOnTheCardVal, std::string typeVal, std::string nameVal)
    : numberOnTheCard(numberOnTheCardVal), type(typeVal), name(nameVal)
{
    points = numberOnTheCard;
}
void Card::play()
{
    // update player score
    // apply effect ( can be moved to only be in purple cards)
    // remove card from player deck add to played cards deck
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
