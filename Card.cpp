#include "Card.hpp"

Card::Card() {}

Card::Card(int scoreVal)
{
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