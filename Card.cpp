
#include "Card.hpp"

Card::Card()
{
    type = "Yellow";
}

Card::Card(int scoreVal, std::string typeVal)
{
    score = scoreVal;
    type = typeVal;
}
void Card::play()
{
    // update player score
    // apply effect ( can be moved to only be in purple cards)
    // remove card from player deck add to played cards deck
}
void Card::set_score(int score)
{
    this->score = score;
}
int Card::get_score() const
{
    return score;
}
std::string Card::getType()
{
    return type;
}