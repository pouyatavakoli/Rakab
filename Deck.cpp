
#include "Deck.hpp"
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