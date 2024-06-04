#include "Yellow9.hpp"

Yellow9::Yellow9() : YellowCard(9, "Yellow9") {}

int Yellow9::get_score() const
{
   return Card::get_score();
}
