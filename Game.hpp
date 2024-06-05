#include <vector>

#include "Player.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
public:
    Game();
    void run();
    void setPlayersCount(int);
    void removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &deckOfCards) ;
    int getHighestYellowCardInGame(std::vector<Player> &);
    std::vector<Player> getGamePlayers() const;

private:
    int playerCount;
    std::vector<Player> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    bool winnerIsPicked;
};

#endif
