#include "Yellow6.hpp"

Yellow6::Yellow6() {}

Yellow6::Yellow6() : YellowCard(6, 6, "Yellow6") {}

int Yellow6::get_score() const
{
   return Card::get_score();
}

int Yellow6::getOriginalScore() const
{
   return YellowCard::getOriginalScore();
}

std::string Yellow6::getType() const
{
   return Card::getType();
}
