#include "Yellow4.hpp"

Yellow4::Yellow4() : YellowCard(4) {}

 int Yellow4::get_score() const
 {
    return Card::get_score();
 }