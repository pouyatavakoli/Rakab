#include <algorithm>

#include "Game.hpp"
#include "Interface.hpp"
#include "Card.hpp"
#include "PurpleCard.hpp"
#include "YellowCard.hpp"
#include "Yellow1.hpp"
#include "Yellow2.hpp"
#include "Yellow3.hpp"
#include "Yellow4.hpp"
#include "Yellow5.hpp"
#include "Yellow6.hpp"
// #include "Yellow7.hpp"
// #include "Yellow8.hpp"
// #include "Yellow9.hpp"
#include "Yellow10.hpp"

Game::Game() : playerCount(0)
{
    winnerIsPicked = false;
}

void Game::setPlayersCount(int PlayerCountVal)
{
    playerCount = PlayerCountVal;
}

void Game::removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &deckOfCards)
{
    auto it = std::find(deckOfCards.begin(), deckOfCards.end(), card);

    if (it != deckOfCards.end())
    {
        deckOfCards.erase(it);
    }
}
void Game::fillMainDeck()
{
    // TODO: add purple cards to main deck
    //  10 yellow1
    for (int i = 1; i <= 10; ++i)
    {
        std::shared_ptr<Yellow1> yellowCard = std::make_shared<Yellow1>();
        mainDeck.push_back(yellowCard);
    }
    // 8 yellow2
    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow2> yellowCard = std::make_shared<Yellow2>();
        mainDeck.push_back(yellowCard);
    }
    // 8 Yellow3
    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow3> yellowCard3 = std::make_shared<Yellow3>();
        mainDeck.push_back(yellowCard3);
    }

    // 8 Yellow4
    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow4> yellowCard4 = std::make_shared<Yellow4>();
        mainDeck.push_back(yellowCard4);
    }

    // 8 Yellow5
    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow5> yellowCard5 = std::make_shared<Yellow5>();
        mainDeck.push_back(yellowCard5);
    }

    // 8 Yellow6
    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow6> yellowCard6 = std::make_shared<Yellow6>();
        mainDeck.push_back(yellowCard6);
    }

    // 8 Yellow10
    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow10> yellowCard10 = std::make_shared<Yellow10>();
        mainDeck.push_back(yellowCard10);
    }

    std::cout << "Main Deck initialized with " << mainDeck.size() << " cards!" << std::endl;
}

void Game::run()
{
    Interface interface;                                  // create interface for the game
    setPlayersCount(interface.getPlayersCountFromUser()); // how many players are gonna play
    for (int i = 0; i < getPlayersCount(); i++)
    {
        Player player;
        players.push_back(player);
    }
    // get players name , age , color
    {
        int i = 0;
        for (Player &player : players)
        {
            player.setName(interface.getPlayersNameFromUser(i));
            player.setAge(interface.getPlayerAgeFromUser(i));
            ++i;
            // TODO: get color
        }
    }
    fillMainDeck();

    // give 10 cards to each player
    // TODO: implement shuffle
    for (int i = 0; i < 10; i++)
    {
        for (Player &player : players)
        {
            if (!mainDeck.empty())
            {
                std::shared_ptr<Card> card = mainDeck.back(); // Get the top card from the main deck
                removeCardFromDeck(card, mainDeck);           // Remove the card from the main deck
                // Add the card to the player's deck
                if (card->getType() == "Purple")
                {
                    player.addCardToPurpleHand(card);
                }
                else if (card->getType() == "Yellow")
                {
                    player.addCardToYellowHand(card);
                }
            }
            else
            {
                std::cout << "main deck is empty cant give cards to players";
            }
        }
    }
    // show players hands
    for (Player &player : players)
    {
        std::cout << player.getName() << " yellow cards : ";
        auto yellowHand = player.getYellowHand();
        for (auto card : yellowHand)
        {
            std::cout << card->getName() << " ";
        }
        std::cout << std::endl;
    }
    // the game starts form here
    while (!winnerIsPicked)
    {
        for (Player &player : players)
        {
            std::string userChoice = interface.askUserToPickACard(player);
            if (userChoice == "Winter")
            {
                // Check if winter exists in player deck
                std::vector<std::shared_ptr<Card>> purpleHand = player.getPurpleHand();
                auto it = std::find_if(purpleHand.begin(), purpleHand.end(), [](const std::shared_ptr<Card> &card)
                                       { return card->getName() == "Winter"; });

                if (it != purpleHand.end())
                {
                    (*it)->play();
                }
                else
                {
                    std::cout << "winter not found in player's deck. Try another card." << std::endl;
                }
            }

            else
            {
                for (int i = 1; i <= 10; ++i)
                {
                    if (i == 7 || i == 8 || i == 9)
                    {
                        continue;
                    }
                    else if (userChoice == "Yellow" + std::to_string(i))
                    {
                        // Check if specific yellow card exists in player deck
                        std::vector<std::shared_ptr<Card>> yellowHand = player.getYellowHand();

                        auto it = std::find_if(yellowHand.begin(), yellowHand.end(), [i](const std::shared_ptr<Card> &card)
                                               { return card->getName() == "Yellow" + std::to_string(i); });

                        if (it != yellowHand.end())
                        {
                            // Play the specific yellow card
                            (*it)->play();
                        }
                        else
                        {
                            std::cout << "Yellow" << i << " not found in player's deck. Try another card." << std::endl;
                        }

                        break; // exit the loop
                    }
                }
            }
        }
    }
}
int Game::getHighestYellowCardInGame(std::vector<Player> &players)
{
    int max = 1;
    for (auto player : players)
    {
        for (auto yellowCard : player.getYellowOnTable())
        {
            if (yellowCard->getPoints() > max)
            {
                max = yellowCard->getPoints();
            }
        }
    }
    return max;
}
std::vector<Player> Game::getGamePlayers() const
{
    return players;
}
void Game::addPlayer(Player player)
{
    players.push_back(player);
}
int Game::getPlayersCount() const
{
    return playerCount;
}