#include "Yellow5.hpp"

Yellow5::Yellow5() : YellowCard(5) {}

 int Yellow5::get_score() const
 {
    return Card::get_score();
 }
