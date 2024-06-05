#include "Yellow1.hpp"

Yellow1::Yellow1() : YellowCard(1, 1, "Yellow1") {}

int Yellow1::get_score() const
{
   return Card::get_score();
}

int Yellow1::getOriginalScore() const
{
   return YellowCard::getOriginalScore();
}

std::string Yellow1::getType() const
{
   return Card::getType();
}
