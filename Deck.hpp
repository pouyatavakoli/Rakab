#include <vector>

#include "Card.hpp"

#ifndef DECK_HPP
#define DECK_HPP
class Deck
{
public:
    Deck();
    void AddToDeck(Card);
    void removeCardFromDeck(Card);
    int getCardsCount();
    void setCardCount(int);
    std::vector<Card> getCardsVector();

private:
    int cardsCount;
    std::vector<Card> deckOfCards;
};
#endif