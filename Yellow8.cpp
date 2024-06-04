#include "Yellow8.hpp"

Yellow8::Yellow8() : YellowCard(8, "Yellow8") {}

int Yellow8::get_score() const
{
   return Card::get_score();
}
