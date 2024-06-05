#include "YellowCard.hpp"

YellowCard::YellowCard() : originalScore(0){}

YellowCard::YellowCard(int point, int O_score, std::string typeVal) : Card(point, typeVal) , originalScore(O_score){}

void YellowCard::set_score(int score)
{
    Card::set_score(score);
}

int YellowCard::getOriginalScore() const
{
    return originalScore;
}
