#include <vector>

#include "Player.hpp"

#ifndef GAME_HPP
#define GAME_HPP


class Game {
public:
    Game(); 
    void run();
    void setPlayersCount(int);
    void removeCardFromDeck(Card card , std::vector<Card> deckOfCards);
private:
    int playerCount;
    std::vector<Player> players;
    std::vector<Card> mainDeck;
    bool winnerIsPicked;
};

#endif
