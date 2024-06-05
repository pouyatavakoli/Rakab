#include "Yellow5.hpp"

Yellow5::Yellow5() : YellowCard(5, 5, "Yellow5") {}

int Yellow5::get_score() const
{
   return Card::get_score();
}

int Yellow5::getOriginalScore() const
{
   return YellowCard::getOriginalScore();
}

std::string Yellow5::getType() const
{
   return Card::getType();
}
