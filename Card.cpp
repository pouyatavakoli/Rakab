#include <string>

#include "Card.hpp"

Card::Card(){
    type = "Yellow"}

Card::Card(int scoreVal, std::string typeVal)
{
    type = typeVal;
    score = scoreVal;
}
void Card::play()
{
    // update player score
    // apply effect ( can be moved to only be in purple cards)
    // remove card from player deck add to played cards deck
}
int Card::get_score() const
{
    return score;
}
std::string Card::getType()
{
    return type;
}