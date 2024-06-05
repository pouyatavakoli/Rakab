#include "Yellow2.hpp"

Yellow2::Yellow2() : YellowCard(2, 2, "Yellow2") {}

int Yellow2::get_score() const
{
   return Card::get_score();
}
