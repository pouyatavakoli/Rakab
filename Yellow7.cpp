#include "Yellow7.hpp"

Yellow7::Yellow7() : YellowCard(7, "Yellow7") {}

int Yellow7::get_score() const
{
   return Card::get_score();
}
