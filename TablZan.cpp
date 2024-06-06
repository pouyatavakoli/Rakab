
#include "TablZan.hpp"

TablZan::TablZan() : PurpleCard(0, "TablZan") {}

void TablZan::effect(Player &player)
{
    std::vector<std::shared_ptr<Card>> deck = player.getYellowOnTable();
    for (auto &card : deck)
    {
        if (card->getType() == "Yellow")
        {
            /* card score was added to players score when the card was played
            now this addition doubles the score in total*/
            player.setScore(player.getPoints() + card->getPoints());
        }
    }
}