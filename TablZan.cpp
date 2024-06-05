
#include "TablZan.hpp"

void TablZan::effect(Player player)
{
    std::vector<Card> deck = player.getPlayerDeck();
    for (Card &card : deck)
    {
        if (card.getType() == "Yellow")
        {
            /* card score was added to players score when the card was played
            now this addition doubles the score in total*/
            player.setPoints(player.getPoints() + card.getPoints());
        }
    }
}