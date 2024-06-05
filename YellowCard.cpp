#include "YellowCard.hpp"

YellowCard::YellowCard() {}

YellowCard::YellowCard(int point, std::string typeVal) : Card(point, typeVal) {}

void YellowCard::set_score(int score)
{
    Card::set_score(score);
}

 std::string YellowCard::getType()
 {
    return Card::getType();
 }
