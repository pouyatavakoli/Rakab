#include <algorithm>

#include "Game.hpp"
#include "Interface.hpp"

Game::Game() : playerCount(0)
{
    winnerIsPicked = false;
}

void Game::setPlayersCount(int PlayerCountVal)
{
    playerCount = PlayerCountVal;
}

void Game::removeCardFromDeck(Card card , std::vector<Card> deckOfCards)
{
    auto it = std::find(deckOfCards.begin(), deckOfCards.end(), card);

    if (it != deckOfCards.end())
    {
        deckOfCards.erase(it);
    }
}


void Game::run()
{
    Interface interface;                                  // create interface for the game
    setPlayersCount(interface.getPlayersCountFromUser()); // how many players are gonna play
    players.resize(playerCount);

    // get players name , age , color
    for (Player &player : players)
    {
        int i = 0;
        player.setName(interface.getPlayersNameFromUser(i));
        player.setAge(interface.getPlayerAgeFromUser(i));
        // TODO: get color
        i++;
    }

    // give 10 cards to each player
    // TODO: implement shuffle
    for (int i = 0; i < 10; i++)
    {
        for (Player &player : players)
        {
            if (!mainDeck.empty())
            {
                Card card = mainDeck.back();                    // Get the top card from the main deck
                removeCardFromDeck(card , mainDeck);            // Remove the card from the main deck
                player.addCardToDeck(card);                       // Add the card to the player's deck
            }
        }
    }
    // the game starts form here
    while (!winnerIsPicked)
    {
        for (Player &player : players)
        {
            std::string userChoice = interface.askUserToPickACard();

            if (userChoice == "TablZan")
            {
                // Check if TablZan exists in player deck
                std::vector<Card> cardsInPlayerDeck = player.getPlayerDeck();
                auto it = std::find(cardsInPlayerDeck.begin(), cardsInPlayerDeck.end(), "TablZan");

                if (it != cardsInPlayerDeck.end())
                {
                    // Play TablZan
                    std::cout << "Playing TablZan for player..." << std::endl;
                }
                else
                {
                    std::cout << "TablZan not found in player's deck. Try again." << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid card choice. Try again." << std::endl;
            }
        }
    }

}
