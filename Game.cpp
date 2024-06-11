#include <algorithm>
#include <ctime>
#include <iomanip>

#include "Game.hpp"
#include "Card.hpp"
#include "Matarsak.hpp"
#include "ShirZan.hpp"
#include "ShirDokht.hpp"
#include "ParchamDar.hpp"
#include "Winter.hpp"
#include "Spring.hpp"
#include "TablZan.hpp"
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
    seasonSituation = "normal";
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

    for (int i = 1; i <= 16; ++i)
    {
        std::shared_ptr<Matarsak> matarsak = std::make_shared<Matarsak>();
        mainDeck.push_back(matarsak);
    }

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<ParchamDar> parchamDar = std::make_shared<ParchamDar>();
        mainDeck.push_back(parchamDar);
    }

    for (int i = 1; i <= 6; ++i)
    {
        std::shared_ptr<TablZan> tablZan = std::make_shared<TablZan>();
        mainDeck.push_back(tablZan);
    }

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
        std::shared_ptr<ShirDokht> shirdokht = std::make_shared<ShirDokht>();
        mainDeck.push_back(shirdokht);
    }

    std::cout << "Main Deck initialized with " << mainDeck.size() << " cards!" << std::endl;
    shuffleDeck();
    std::cout << "Main Deck got shuffled. " << std::endl;
}

// starts the whole game
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
            player.setColor(interface.askUserToPickAColor(i));
            ++i;
            // FIXME: change pick color to user pick from list if needed
        }
    }
    fillMainDeck();

    // give 10 cards to each player
    handCardsToPLayers();

    // show all players hands (may be removed in future)
    std::cout << "all hands summary :" << std::endl;
    for (Player &player : players)
    {
        std::cout << player.getName() << " cards : ";
        auto yellowHand = player.getYellowHand();
        for (auto card : yellowHand)
        {
            std::cout << std::setw(10) << card->getName() << " ";
        }
        auto purpleHand = player.getPurpleHand();
        for (auto card : purpleHand)
        {
            std::cout << std::setw(10) << card->getName() << " ";
        }
        std::cout << std::endl;
    }

    int count{0};
    while (true)
    {
        if (count == 0)
        {
            setBattleStarter(findSmallestPlayer()); // ask smallest player to pick battle province
            startBattle(interface.askSmallestPlayerToPickBattleProvince(findSmallestPlayer()), interface);
        }
        else
        {
            // setBattleStarter(); //the winner of previous game should start
        }
        count++;
    }
}

void Game::startBattle(const std::string &province, Interface &interface)
{
    std::cout << "Battle started on province: " << province << std::endl;
    while (!winnerIsPicked)
    {
        anyPlayerCanPlay = false;
        for (Player &player : players)
        {
            int situation{0};
            if (player.canPlay())
            {
                anyPlayerCanPlay = true;
                std::string userChoice = interface.askUserToPickACardOrPass(player);
                situation = player.PlayThisCard(userChoice);
                // start season
                if (situation == 2)
                {
                    startSeason(userChoice);
                    seasonSituation = userChoice;
                }
                // pass
                else if (situation == -1)
                {
                    std::cout << player.getName() << " has passed" << std::endl;
                }
                // notfound
                else if (situation == 0)
                {
                    std::cout << userChoice << " was not found " << std::endl;
                }

                updateTotalScore();
                if (seasonSituation != "normal")
                {
                    refreshSeason(seasonSituation);
                }
            }
            else
            {
                std::cout << player.getName() << " cannot play going to next player..." << std::endl;
                // FIXME: show this massage once for each player
            }
        }
        if (!anyPlayerCanPlay)
        {
            std::cout << "No one can play. The game has ended." << std::endl;
            checkThisBattleWinner(province); // not sure about the rules
            break;
        }
    }
}
void Game::checkThisBattleWinner(const std::string &province)
{

    int max{0};
    Player *winner = nullptr;
    // find max score
    for (auto &player : players)
    {
        if (player.getPoints() >= max)
        {
            max = player.getPoints();
            winner = &player;
        }
    }
    int tieCounter{0};
    // count players with max score
    for (auto &player : players)
    {
        if (player.getPoints() == max)
        {
            tieCounter++;
        }
    }
    // if there are more than 1 max, its a tie
    if (tieCounter > 1)
    {
        std::cout << "The game has no winner, it's a tie." << std::endl;
    }
    else if (winner != nullptr)
    {
        std::cout << winner->getName() << " captured " << province << " with " << winner->getPoints() << " points." << std::endl;
        winner->addOwnedProvinces(province);
    }
    else
    {
        std::cout << "No winner could be determined." << std::endl;
    }
}

int Game::getHighestYellowCardInGame()
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

void Game::addPlayer(Player player)
{
    players.push_back(player);
}

int Game::getPlayersCount() const
{
    return playerCount;
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
void Game::updateTotalScore()
{
    for (auto &player : players)
    {
        int totalOnTable = 0;

        for (auto card : player.getYellowOnTable())
        {
            totalOnTable += card->getPoints();
        }
        for (auto card : player.getPurpleOnTable())
        {
            totalOnTable += card->getPoints();
        }
        player.setScore(totalOnTable);
    }
}

void Game::handCardsToPLayers()
{
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
}

const Player &Game::findSmallestPlayer()
{
    if (players.empty())
    {
        static Player defaultPlayer; // Return a default player if no players are found
        return defaultPlayer;
    }

    const Player *smallestPlayer = &players[0];
    int minAge = players[0].getAge();

    for (const auto &player : players)
    {
        if (player.getAge() < minAge)
        {
            minAge = player.getAge();
            smallestPlayer = &player;
        }
    }

    return *smallestPlayer;
}

void Game::setBattleStarter(const Player &player1)
{
    int playerIndex = -1;

    // Find the player
    for (int i = 0; i < playerCount; i++)
    {
        if (players[i].getName() == player1.getName())
        {
            playerIndex = i;
            break;
        }
    }

    if (playerIndex != -1) /*If player is found,
                           rotate array so that playerIndex is at the start*/

    {
        std::vector<Player> newOrder;

        // Add players from playerIndex to the end
        for (int i = playerIndex; i < playerCount; i++)
        {
            newOrder.push_back(players[i]);
        }

        // Add players from the start to playerIndex-1
        for (int i = 0; i < playerIndex; i++)
        {
            newOrder.push_back(players[i]);
        }

        // Update the order
        for (int i = 0; i < playerCount; i++)
        {
            players[i] = newOrder[i];
        }
    }
}
void Game::winGame1(Player &player, Map &map)
{
    const auto &ownedProvinces = player.getOwnedProvinces();

    for (const auto &province : ownedProvinces)
    {
        const auto &adjacentProvinces = map.get_adjacent_provinces(province);
        int adjacentCount = 0;

        for (const auto &adjacentProvince : adjacentProvinces)
        {
            if (province == adjacentProvince)
            {
                adjacentCount++;
            }
            if (adjacentCount >= 2)
            {
                player.setWinStatus(true);
                break;
            }
        }
    }
}

void Game::winGame2()
{
    for (auto &player : players)
    {
        if (player.getNumberOfOwnedProvinces() >= 5)
        {
            player.setWinStatus(true);
            break;
        }
    }
}

void Game::findWinner()
{
    for (auto player : players)
    {
        if (player.getWinStatus())
        {
            std::cout << player.getName() << "is the winner of Game" << std::endl;
            break;
        }
    }
}

void Game::startSeason(const std::string userChoice)
{
    if (userChoice == "Winter")
    {
        endSeason("Spring");
        std::cout << "Winter has started." << std::endl;
        for (auto &changePlayer : players)
        {
            for (auto &yellowcards : changePlayer.getYellowOnTable())
            {
                if (yellowcards->getPoints() != 1)
                {
                    yellowcards->setPoints(1);
                }
            }
        }
    }
    else if (userChoice == "Spring")
    {
        endSeason("Winter");
        std::cout << "Spring has started." << std::endl;
        int max = getHighestYellowCardInGame();
        for (auto &player : players)
        {
            for (auto &yellowCard : player.getYellowOnTable())
            {
                if (yellowCard->getPoints() == max)
                {
                    yellowCard->setPoints(max + 3);
                }
            }
        }
    }
    updateTotalScore();
}

void Game::endSeason(const std::string userChoice)
{
    if (userChoice == "Winter")
    {
        for (auto &changePlayer : players)
        {
            for (auto &yellowcards : changePlayer.getYellowHand())
            {
                if (yellowcards->getType() != "Yellow1")
                {
                    yellowcards->setPoints(yellowcards->getNumerOnTheCard());
                }
            }
        }
    }
    else if (userChoice == "Spring")
    {
        for (auto &player : players)
        {
            for (auto &yellowCard : player.getYellowOnTable())
            {
                yellowCard->setPoints(yellowCard->getNumerOnTheCard());
            }
        }
    }
    updateTotalScore();
}
void Game::refreshSeason(const std::string userChoice)
{
    endSeason(userChoice);
    startSeason(userChoice);
}