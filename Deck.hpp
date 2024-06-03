#include <vector>

#include "Card.hpp"

#ifndef DECK_HPP
#define DECK_HPP
class Deck
{
public:
    void AddToDeck(Card);
    int getCardsCount();

private:
    int cardsCount;
    std::vector<Card> deckOfCards;
};
#endif