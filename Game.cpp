#include <algorithm>
#include <ctime>
#include <iomanip>
#include <map>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

#include "Game.hpp"
#include "Card.hpp"
#include "Matarsak.hpp"
#include "ShirDokht.hpp"
#include "Winter.hpp"
#include "Spring.hpp"
#include "TablZan.hpp"
// #include "ParchamDar.hpp"
// #include "ShirZan.hpp"
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
    cardHoldersCount = 0;
}

void Game::help()
{
    std::map<std::string, std::string> helpMap =
        {
            {"help", "List of helps you can get : game , matarsak , winter , bahar , ... "}, // TODO: complete
            {"help game", "Help text for game"},
            {"help matarsak", "get one yellow card off table back to hand"},
            {"help TablZan", "doubles yellow cards"},
            {"help bahar", "ends winter adds 3 to biggest yellow"}};

    std::string command;
    std::cout << "Enter a command , enter q to exit : ";
    std::cin.ignore();
    std::getline(std::cin, command);

    if (command == "q")
    {
        return;
    }

    if (helpMap.find(command) != helpMap.end())
    {
        std::cout << helpMap[command] << std::endl;
    }
    else
    {
        std::cout << "Command not found. Type 'help' for the list of available commands." << std::endl;
    }
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

    /*for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<ParchamDar> parchamDar = std::make_shared<ParchamDar>();
        mainDeck.push_back(parchamDar);
    }*/

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

    /*for (int i = 1; i <= 12; ++i)
    {
        std::shared_ptr<ShirZan> shirzan = std::make_shared<ShirZan>();
        mainDeck.push_back(shirzan);
    }*/

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
    clearScreen();
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
            std::cout << "***   PLAYER  " << i + 1 << "   ***" << std::endl;
            player.setName(interface.getPlayersNameFromUser(i));
            player.setAge(interface.getPlayerAgeFromUser(i));
            player.setColor(interface.askUserToPickAColor(i));
            ++i;
            clearScreen();
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

    bool firstRound = true;
    while (true)
    {
        if (firstRound)
        {

            firstRound = false;
            setBattleStarter(findSmallestPlayer()); // ask smallest player to pick battle province
            while (true)
            {
                std::string targetProvince = interface.askPlayerToPickBattleProvince(findSmallestPlayer());
                clearScreen();
                if (map.findProvince(targetProvince)) // TODO : duplicated province
                {
                    startBattle(targetProvince, interface);
                    break;
                }
                else
                {
                    std::cout << "Such province doesn't exist, try another one." << std::endl;
                }
            }
        }
        else
        {
            // the winner of previous game should start next battle
            setBattleStarter(getPlayerWhoShouldStart());
            while (true)
            {
                bool canPlayThisProvince = true;
                std::string targetProvince = interface.askPlayerToPickBattleProvince(getPlayerWhoShouldStart());
                if (map.findProvince(targetProvince))
                {
                    for (auto &player : players)
                        for (auto &province : player.getOwnedProvinces())
                        {
                            if (province == targetProvince)
                            {
                                canPlayThisProvince = false;
                                std::cout << "this province is already owned ,try another one" << std::endl;
                                continue;
                            }
                        }
                }
                else
                {
                    canPlayThisProvince = false;
                }
                if (canPlayThisProvince)
                {
                    clearScreen();
                    startBattle(targetProvince, interface);
                    break;
                }
                else
                {
                    std::cout << "Such province doesn't exist, try another one." << std::endl;
                }
            }
        }
        if (winGame1()) // if a player has three adjacent provinces , wins
        {
            findWinner();
            break;
        }
        if (winGame2()) // if a player has five provinces , wins
        {
            findWinner();
            break;
        }
    }
}

void Game::startBattle(const std::string &province, Interface &interface)
{
    // Reset player eligibility each time this function is called for the next battle
    for (Player &player : players)
    {
        // FIXME: player should not update its own eligibility (maybe)
        player.updatePlayerEligibility(true);
        // Move cards from table to burnt cards
        player.flushTable();
        updateTotalScore();
        updateCardHoldersCount();
    }

    std::cout << "Battle started on province: " << province << std::endl;
    while (!winnerIsPicked)
    {
        anyPlayerCanPlay = false;
        for (Player &player : players)
        {
            while (cardHoldersCount > 1)
            {
                int situation{0};

                if (player.canPlay())
                {
                    anyPlayerCanPlay = true;
                    std::string userChoice = interface.askUserToPickACardOrPass(player);
                    updateCardHoldersCount();
                    if (userChoice == "burn")
                    {
                        if (player.getYellowHand().size() == 0)
                        {
                            player.burnHand();
                            player.updatePlayerEligibility(false);
                        }
                        else
                        {
                            std::cout << "you still have " << player.getYellowHand().size() << " yellow cards in hand pass or play you cannot burn your hand" << std::endl;
                        }
                    }
                    if (userChoice == "Winter" || userChoice == "Spring")
                    {
                        if (canStartSeason(userChoice))
                        {
                            situation = player.PlayThisCard(userChoice);
                        }
                        else
                        {
                            std::cout << userChoice << " Can not be Played. Please pick a card or pass." << std::endl;
                            continue;
                        }
                    }
                    else
                    {
                        situation = player.PlayThisCard(userChoice);
                    }
                    // updateTotalScore();

                    // Check the situation after trying to play a card
                    if (situation == -1) // Pass
                    {
                        std::cout << player.getName() << " has passed or burnt his/her hand" << std::endl;
                        lastPlayerWhoPassed = &player; // Update the last player who passed
                        break;                         // Exit the while loop to go to the next player
                    }
                    else if (situation == -10) // show help
                    {
                        help();
                        continue;
                    }
                    else if (situation == 0) // Card not found
                    {
                        std::cout << userChoice << " was not found. Please pick a card or pass." << std::endl;
                        continue; // Continue prompting the same player
                    }
                    else if (situation == 1) // Successfully played a card
                    {
                        break; // Exit the while loop to go to the next player
                    }
                    else if (situation == 2) // It is a season
                    {
                        seasonSituation = userChoice;
                        break; // Exit the while loop to go to the next player
                    }
                    else if (situation == 2)
                    {
                        std::cout << userChoice << " Can not be Played. Please pick a card or pass." << std::endl;
                        continue;
                    }
                }
                else
                {
                    std::cout << player.getName() << " cannot play. Going to next player..." << std::endl;
                    break; // Exit the while loop to go to the next player
                }
            }
            updateTotalScore();
            if (cardHoldersCount <= 1)
            {
                std::cout << "there are not enough card holders in this game handing the cards again..." << std::endl;
                for (auto &player : players)
                {
                    std::cout << "burning hands ..." << std::endl;
                    player.burnHand();
                }
                handCardsToPLayers();
                updateCardHoldersCount();
            }
            clearScreen();
        }

        if (!anyPlayerCanPlay)
        {
            std::cout << "No one can play. The game has ended." << std::endl;
            checkThisBattleWinner(province); // Not sure about the rules
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
        setLastWinner(*winner);
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
    refreshEffects();
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

void Game::reorderPurpleOnTable()
{
    // Define the order for the card types
    std::unordered_map<std::string, int> orderMap = {
        {"Winter", 1},
        {"TablZan", 2},
        {"Spring", 3},
        {"ShirDokht", 4}};

    for (auto &player : players)
    {
        std::vector<std::shared_ptr<Card>> purplesOnTable = player.getPurpleOnTable();

        // comparison function
        auto compareCards = [&orderMap](const std::shared_ptr<Card> &a, const std::shared_ptr<Card> &b)
        {
            return orderMap[a->getType()] < orderMap[b->getType()];
        };

        // Sort the cards
        std::sort(purplesOnTable.begin(), purplesOnTable.end(), compareCards);

        //  set the sorted cards back to the player
        player.setPurpleOnTable(purplesOnTable);
    }
    /*for (auto player : players)  //Just to if the order is right or not
    {
        for (auto cards : player.getPurpleOnTable())
        {
            std::cout << cards->getName() << " is  ";
        }
        std::cout << std::endl;
    }*/
}

void Game::endAllEffects()
{
    for (auto &player : players)
    {
        player.cancelEffects();
    }
}

void Game::startAllEffects()
{
    if (seasonSituation == "Winter")
    {
        startSeason("Winter");
        std::cout << "Winter started in game func" << std::endl;
        for (auto &player : players)
        {
            player.applyEffect();
        }
    }
    else if (seasonSituation == "Spring")
    {
        for (auto &player : players)
        {
            player.applyEffect();
        }
        std::cout << "spring started in game func" << std::endl;
        startSeason("Spring");
    }
    else
    {
        for (auto &player : players)
        {
            player.applyEffect();
        }
    }
}

void Game::refreshEffects()
{
    endAllEffects();
    reorderPurpleOnTable();
    startAllEffects();
}

void Game::handCardsToPLayers()
{
    std::cout << "handing cards to players..." << std::endl;
    for (Player &player : players)
    {
        for (int i = 0; i < 10 + player.getNumberOfOwnedProvinces(); i++)
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

    std::vector<const Player *> smallestPlayers;
    int minAge = players[0].getAge();

    for (const auto &player : players)
    {
        if (player.getAge() < minAge)
        {
            minAge = player.getAge();
            smallestPlayers.clear();
            smallestPlayers.push_back(&player);
        }
        else if (player.getAge() == minAge)
        {
            smallestPlayers.push_back(&player);
        }
    }

    // Seed the random number generator
    std::srand(std::time(0));

    // Randomly select one of the youngest players
    int randomIndex = std::rand() % smallestPlayers.size();

    return *(smallestPlayers[randomIndex]);
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
bool Game::winGame1()
{
    for (auto &player : players)
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
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::winGame2()
{
    for (auto &player : players)
    {
        if (player.getNumberOfOwnedProvinces() >= 5)
        {
            player.setWinStatus(true);
            return true;
        }
    }
    return false;
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
        removeGameSeason("Spring");
        seasonSituation = "Winter";
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

        removeGameSeason("Winter");
        seasonSituation = "Spring";

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
    else
    {
        std::cerr << "Season does not exist: " << userChoice << std::endl;
    }
}

void Game::endSeason(const std::string &userChoice)
{
    if (userChoice == "Winter" && seasonSituation == "Winter")
    {
        for (auto &player : players)
        {
            for (auto &yellowCard : player.getYellowOnTable())
            {
                yellowCard->setPoints(yellowCard->getNumerOnTheCard());
            }
        }
    }
    else if (userChoice == "Spring" && seasonSituation == "Spring")
    {
        for (auto &player : players)
        {
            for (auto &yellowCard : player.getYellowOnTable())
            {
                yellowCard->setPoints(yellowCard->getNumerOnTheCard());
            }
        }
    }
}

/*void Game::refreshSeason(const std::string userChoice) //In new update it isn't needed
{
    endSeason(userChoice);
    startSeason(userChoice);
}*/

bool Game::canStartSeason(const std::string season) const
{
    if (seasonSituation == season)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Game::removeGameSeason(const std::string userChoice)
{
    for (auto &player : players)
    {
        player.removeSeasonOnTheTable(userChoice);
    }
}

Player Game::getPlayerWhoShouldStart()
{
    if (lastWinner.getName().empty())
    {
        return *lastPlayerWhoPassed;
    }
    else
    {
        return lastWinner;
    }
}
void Game::setLastWinner(Player winnerVal)
{
    lastWinner = winnerVal;
}

void Game::updateCardHoldersCount()
{
    for (auto &player : players)
    {
        if (player.getYellowHand().size() > 0 || player.getPurpleHand().size() > 0)
        {
            ++cardHoldersCount;
        }
    }
}

void Game::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}