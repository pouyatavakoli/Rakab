#include "Yellow10.hpp"

Yellow10::Yellow10() : YellowCard(10, 10, "Yellow10") {}

int Yellow10::get_score() const
{
   return Card::get_score();
}

int Yellow10::getOriginalScore() const
{
   return YellowCard::getOriginalScore();
}

std::string Yellow10::getType() const
{
   return Card::getType();
}
