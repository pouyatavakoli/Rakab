#include "Card.hpp"

Card::Card() {}

Card::Card(int scoreVal)
{
    score = scoreVal;
}

 int Card::get_score() const
{
    return score;
}