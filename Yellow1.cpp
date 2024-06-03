#include "Yellow1.hpp"

Yellow1::Yellow1() {}

Yellow1::Yellow1(int point) : YellowCard(point) {}

 int Yellow1::get_score() const
 {
    return Card::get_score();
 }
