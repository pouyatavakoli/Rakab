#include <vector>

#include "Card.hpp"

#ifndef DECK_HPP
#define DECK_HPP
class Deck
{
public:
    void AddToDeck(Card);
    void removeCardFromDeck(Card);
    int getCardsCount();
    std::vector<Card> getCardsVector();

private:
    int cardsCount;
    std::vector<Card> deckOfCards;
};
#endif