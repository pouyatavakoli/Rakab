#include "Yellow10.hpp"

Yellow10::Yellow10() : YellowCard(10, "Yellow10") {}

int Yellow10::get_score() const
{
   return Card::get_score();
}
