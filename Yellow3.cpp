#include "Yellow3.hpp"

Yellow3::Yellow3() {}

Yellow3::Yellow3() : YellowCard(3, 3, "Yellow3") {}

int Yellow3::get_score() const
{
   return Card::get_score();
}

int Yellow3::getOriginalScore() const
{
   return YellowCard::getOriginalScore();
}

