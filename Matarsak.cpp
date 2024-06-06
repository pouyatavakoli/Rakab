#include "Matarsak.hpp"
#include <iostream>

Matarsak::Matarsak() : PurpleCard(0, "Matarsak") {}

void Matarsak::effect(Player &player)
{
    std::cout << "What card do you want to take? (Yellow1, Yellow2, ..., Yellow10): ";
    std::string cardName;
    std::cin >> cardName;

    std::shared_ptr<Card> targetCard = player.removeCardFromYellowOnTable(cardName);

    if (targetCard)
    {
        std::cout << "Card " << cardName << " has been taken and removed from the table and added to hand." << std::endl;
        player.addCardToYellowHand(targetCard);
    }
    else
    {
        std::cout << "Card " << cardName << " not found on the table." << std::endl;
    }
}
