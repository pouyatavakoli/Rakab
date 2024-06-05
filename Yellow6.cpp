#include "Yellow6.hpp"

Yellow6::Yellow6() {}

Yellow6::Yellow6() : YellowCard(6, 6, "Yellow6") {}

int Yellow6::get_score() const
{
   return Card::get_score();
}
