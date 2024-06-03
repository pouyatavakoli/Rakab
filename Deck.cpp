#include <algorithm>

#include "Deck.hpp"

Deck::Deck()
{
    cardsCount = 0;
}

void Deck::AddToDeck(Card card)
{
    deckOfCards.push_back(card);
}
int Deck::getCardsCount()
{
    return cardsCount;
}
std::vector<Card> Deck::getCardsVector()
{
    return deckOfCards;
}
void Deck::removeCardFromDeck(Card card)
{
    auto it = std::find(deckOfCards.begin(), deckOfCards.end(), card);

    if (it != deckOfCards.end())
    {
        deckOfCards.erase(it);
        cardsCount--;
    }
}
void Deck::setCardCount(int countVal)
{
    cardsCount = countVal;
}