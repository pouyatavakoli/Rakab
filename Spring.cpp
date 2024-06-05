#include "Spring.hpp"

Spring::Spring() : Season(0, "Spring") {}

// adds 3 to highest card
void Spring::start(Game &game)
{
    std::vector<Player> players = game.getGamePlayers();
    int max = game.getHighestYellowCardInGame(players);
    for (auto player : players)
    {
        for (auto &yellowCard : player.getPlayedYellowDeck())
        {
            if (yellowCard->get_score() == max)
            {
                yellowCard->set_score(max + 3);
            }
        }
    }
}

// revert to default scores
void Spring::end(Game &game)
{
    std::vector<Player> players = game.getGamePlayers();
    for (auto &player : players)
    {
        for (auto &yellowCard : player.getPlayedYellowDeck())
        {
            yellowCard->set_score(yellowCard->getOriginalScore());
        }
    }
}

// revert cards to original and sets spring again
void Spring::refresh(Game &game)
{
    end(game);
    start(game);
}

std::string Spring::getType() const
{
    return Card::getType();
}