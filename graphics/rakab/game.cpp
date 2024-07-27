#include <ctime>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

#include "game.hpp"
#include "card.h"
//#include "Matarsak.h"
#include "shahdokht.h"
#include "winter.h"
#include "spring.h"
//#include "TablZan.h"
#include "parchamdar.h"
#include "rishsefid.h"
#include "shirzan.h"
#include "yellow1.h"
#include "yellow2.h"
#include "yellow3.h"
#include "yellow4.h"
#include "yellow5.h"
#include "yellow6.h"
#include "yellow10.h"

// Constructor
Game::Game(QObject *parent) : QObject(parent), playerCount(0), currentPlayerIndex(0) {}

// Setter for player count
void Game::setPlayersCount(int PlayerCountVal) {
    playerCount = PlayerCountVal;
}

void Game::setPlayers(const std::vector<std::string>& names, const std::vector<int>& ages) {

    // Create new players based on names and ages
    for (size_t i = 0; i < names.size(); ++i) {
        Player* player = new Player();
        player->setName(names[i]);
        player->setAge(ages[i]);
        players.push_back(player);
    }
}


// Advances to the next turn
void Game::nextTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    emit turnChanged(currentPlayerIndex);
}

void Game::fillMainDeck()
{
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
/*
    for (int i = 1; i <= 16; ++i)
    {
        std::shared_ptr<Matarsak> matarsak = std::make_shared<Matarsak>();
        mainDeck.push_back(matarsak);
    }*/

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<ParchamDar> parchamDar = std::make_shared<ParchamDar>();
        mainDeck.push_back(parchamDar);
    }

    /*for (int i = 1; i <= 6; ++i)
    {
        std::shared_ptr<TablZan> tablZan = std::make_shared<TablZan>();
        mainDeck.push_back(tablZan);
    }*/

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<Spring> spring = std::make_shared<Spring>();
        mainDeck.push_back(spring);
    }

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<Winter> winter = std::make_shared<Winter>();
        mainDeck.push_back(winter);
    }

    for (int i = 1; i <= 12; ++i)
    {
        std::shared_ptr<ShirZan> shirzan = std::make_shared<ShirZan>();
        mainDeck.push_back(shirzan);
    }

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<ShahDokht> shahdokht = std::make_shared<ShahDokht>();
        mainDeck.push_back(shahdokht);
    }

    for (int i = 1; i <= 6; ++i)
    {
        std::shared_ptr<RishSefid> rishsefid = std::make_shared<RishSefid>();
        mainDeck.push_back(rishsefid);
    }

}

void Game::shuffleDeck()
{
    std::srand(std::time(nullptr)); // Seed the random number generator with current time

    for (int i = mainDeck.size() - 1; i > 0; --i)
    {
        int j = std::rand() % (i + 1); // Generate a random index in the range [0, i]
        std::swap(mainDeck[i], mainDeck[j]);
    }
}

int Game::getHighestYellowCardInGame() const
{
    int max = 1;
    for (auto player : players)
    {
        for (const auto &yellowCard : player->getYellowOnTable())
        {
            if (yellowCard->getPoints() > max)
            {
                max = yellowCard->getPoints();
            }
        }
    }
    return max;
}

int Game::getPlayerCount() const
{
    return playerCount;
}

const Player& Game::getPlayer(int index) {
    if (index < 0 || index >= players.size()) {
        throw std::out_of_range("Player index out of range");
    }
    return *players[index];
}

void Game::updateCardHoldersCount()
{
    for (auto &player : players)
    {
        if (player->getYellowHand().size() > 0 || player->getPurpleHand().size() > 0)
        {
            ++cardHoldersCount;
        }
    }
}

void Game::handCardsToPLayers()
{
//    std::cout << "handing cards to players..." << std::endl;
    for (Player *player : players)
    {
        for (int i = 0; i < 10 + player->getNumberOfOwnedProvinces(); i++)
        {
            if (!mainDeck.empty())
            {
                std::shared_ptr<Card> card = mainDeck.back(); // Get the top card from the main deck
                removeCardFromDeck(card, mainDeck);           // Remove the card from deck
                // Add the card to the player's deck
                if (card->getType() == "Purple")
                {
                    player->addCardToPurpleHand(card);
                }
                else if (card->getType() == "Yellow")
                {
                    player->addCardToYellowHand(card);
                }
            }
            else
            {
//                std::cout << "main deck is empty cant give cards to players";
            }
        }
    }
}

void Game::removeCardFromDeck(std::shared_ptr<Card> card, std::vector<std::shared_ptr<Card>> &deckOfCards)
{
    auto it = std::find(deckOfCards.begin(), deckOfCards.end(), card);

    if (it != deckOfCards.end())
    {
        deckOfCards.erase(it);
    }
}

void Game::reorderPurpleOnTable()
{
    // Define the order for the card types
    std::unordered_map<std::string, int> orderMap = {
        {"RishSefid", 1},
        {"Winter", 2},
        {"TablZan", 3},
        {"Spring", 4},
        {"ShirDokht", 5}};

    for (auto &player : players)
    {
        std::vector<std::shared_ptr<Card>> purplesOnTable = player->getPurpleOnTable();

        // comparison function
        auto compareCards = [&orderMap](const std::shared_ptr<Card> &a, const std::shared_ptr<Card> &b)
        {
            return orderMap[a->getType()] < orderMap[b->getType()];
        };

        // Sort the cards
        std::sort(purplesOnTable.begin(), purplesOnTable.end(), compareCards);

        //  set the sorted cards back to the player
        player->setPurpleOnTable(purplesOnTable);
    }
}

bool Game::playCard(int playerIndex, const std::string &cardName) {
    Player& player = *players[playerIndex];
    int result = player.PlayThisCard(cardName);

    if (result == 1) {
        emit cardPlayed(playerIndex, QString::fromStdString(cardName));
        return true;
    } else {
        emit cardCannotBePlayed(playerIndex, QString::fromStdString(cardName));
        return false;
    }
}

std::vector<std::shared_ptr<Card>> Game::getMainDeck(){
    return mainDeck ;
}
