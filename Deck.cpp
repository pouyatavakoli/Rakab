#include "Deck.hpp"
void Deck::AddToDeck(Card card)
{
    deckOfCards.push_back(card);
}
int Deck::getCardsCount()
{
    return cardsCount;
}