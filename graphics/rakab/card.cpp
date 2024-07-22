#include "card.h"

Card::Card(int numberOnTheCardVal, const std::string &typeVal, const std::string &nameVal, QObject *parent)
    : QObject(parent), name(nameVal), type(typeVal), numberOnTheCard(numberOnTheCardVal)
{
    points = numberOnTheCard;
}
