#include "Winter.hpp"

Winter::Winter() : Season() {}
void Winter::start(std::vector<Player> &player)
{
    for (auto &changePlayer : player)
    {
        for (auto &yellowcards : changePlayer.getYellowHand())
        {
            if (yellowcards->get_score() != 1 || yellowcards->getType() != "Yellow1")
            {
                original_scores.push_back(yellowcards);
                yellowcards->set_score(1);
            }
        }
    }
}

void end(std::vector<Player> &player)
{

}