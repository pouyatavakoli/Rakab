#include <ctime>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <QMessageBox>

#include "mapwindow.h"

#include "game.hpp"
#include "card.h"
#include "matarsak.h"
#include "shahdokht.h"
#include "winter.h"
#include "spring.h"
#include "tablzan.h"
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
Game::Game( QObject *parent) : QObject(parent), playerCount(0), currentPlayerIndex(0)
  ,lastWinner(nullptr) , NeshaneJangOwner(nullptr) , NeshaneSolhOwner(nullptr)
  , lastPlayerWhoPassed(nullptr) {
    neshaneSolhProvince = "None";
}

// Setter for player count
void Game::setPlayersCount(int PlayerCountVal) {
    playerCount = PlayerCountVal;
}

void Game::setPlayers(const std::vector<std::string>& names, const std::vector<int>& ages , const std::vector<std::string>& colors) {

    // Create new players based on names and ages
    for (size_t i = 0; i < names.size(); ++i) {
        Player* player = new Player();
        player->setName(names[i]);
        player->setAge(ages[i]);
        player->setColor(colors[i]);
        players.push_back(player);
    }
}

void Game::setPlayers(std::vector<std::shared_ptr<Player>> playersVal)
{
    players.clear();          // Clear the existing players vector

    for (auto player : playersVal){
        auto name = player->getName();
        auto age  = player->getAge();
        auto yellowHand = player->getYellowHand();

        Player* newplayer = new Player(age , name);
        for(auto card : yellowHand){
            newplayer->addCardToYellowHand(card);
        }
        players.push_back(newplayer);
    }
}



void Game::fillMainDeck()
{
    /*
    std::map<std::string, std::string> cardImages;
    cardImages["RishSefid"] = ":/new/cards/banafsh/assets/cards/banafsh/Rish_Sefid.png";
    cardImages["ShahDokht"] = ":/new/cards/banafsh/assets/cards/banafsh/Shah_Dokht.png";
    cardImages["ShirZan"] = ":/new/cards/banafsh/assets/cards/banafsh/Shir_Zan.png";
    cardImages["Winter"] = ":/new/cards/banafsh/assets/cards/banafsh/Zemestan.png";
    cardImages["Spring"] = ":/new/cards/banafsh/assets/cards/banafsh/Bahar.png";
    cardImages["Matarsak"] = ":/new/cards/banafsh/assets/cards/banafsh/Matarsak.png";
    cardImages["ParchamDar"] = ":/new/cards/banafsh/assets/cards/banafsh/Parcham_Dar.png";
    cardImages["TablZan"] = ":/new/cards/banafsh/assets/cards/banafsh/Tabl_Zan.png";
    cardImages["Yellow1"] = ":/new/cards/zard/assets/cards/zard/001.png";
    cardImages["Yellow2"] = ":/new/cards/zard/assets/cards/zard/002.png";
    cardImages["Yellow3"] = ":/new/cards/zard/assets/cards/zard/003.png";
    cardImages["Yellow4"] = ":/new/cards/zard/assets/cards/zard/004.png";
    cardImages["Yellow5"] = ":/new/cards/zard/assets/cards/zard/005.png";
    cardImages["Yellow6"] = ":/new/cards/zard/assets/cards/zard/006.png";
    cardImages["Yellow10"] = ":/new/cards/zard/assets/cards/zard/010.png";
    */

    for (int i = 1; i <= 10; ++i)
    {
        std::shared_ptr<Yellow1> yellowCard1 = std::make_shared<Yellow1>();
        //yellowCard1->setImage(QString::fromStdString(cardImages["Yellow1"]));
        mainDeck.push_back(yellowCard1);
    }

    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow2> yellowCard2 = std::make_shared<Yellow2>();
        //yellowCard2->setImage(QString::fromStdString(cardImages["Yellow2"]));
        mainDeck.push_back(yellowCard2);
    }

    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow3> yellowCard3 = std::make_shared<Yellow3>();
        //yellowCard3->setImage(QString::fromStdString(cardImages["Yellow3"]));
        mainDeck.push_back(yellowCard3);
    }

    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow4> yellowCard4 = std::make_shared<Yellow4>();
        //yellowCard4->setImage(QString::fromStdString(cardImages["Yellow4"]));
        mainDeck.push_back(yellowCard4);
    }

    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow5> yellowCard5 = std::make_shared<Yellow5>();
        //yellowCard5->setImage(QString::fromStdString(cardImages["Yellow5"]));
        mainDeck.push_back(yellowCard5);
    }

    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow6> yellowCard6 = std::make_shared<Yellow6>();
        //yellowCard6->setImage(QString::fromStdString(cardImages["Yellow6"]));
        mainDeck.push_back(yellowCard6);
    }

    for (int i = 1; i <= 8; ++i)
    {
        std::shared_ptr<Yellow10> yellowCard10 = std::make_shared<Yellow10>();
        //yellowCard10->setImage(QString::fromStdString(cardImages["Yellow10"]));
        mainDeck.push_back(yellowCard10);
    }

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<ParchamDar> parchamDar = std::make_shared<ParchamDar>();
        //parchamDar->setImage(QString::fromStdString(cardImages["ParchamDar"]));
        mainDeck.push_back(parchamDar);
    }

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<Spring> spring = std::make_shared<Spring>();
        //spring->setImage(QString::fromStdString(cardImages["Spring"]));
        mainDeck.push_back(spring);
    }

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<Winter> winter = std::make_shared<Winter>();
        //winter->setImage(QString::fromStdString(cardImages["Winter"]));
        mainDeck.push_back(winter);
    }

    for (int i = 1; i <= 12; ++i)
    {
        std::shared_ptr<ShirZan> shirzan = std::make_shared<ShirZan>();
        //shirzan->setImage(QString::fromStdString(cardImages["ShirZan"]));
        mainDeck.push_back(shirzan);
    }

    for (int i = 1; i <= 3; ++i)
    {
        std::shared_ptr<ShahDokht> shahdokht = std::make_shared<ShahDokht>();
        //shahdokht->setImage(QString::fromStdString(cardImages["ShahDokht"]));
        mainDeck.push_back(shahdokht);
    }

    for (int i = 1; i <= 6; ++i)
    {
        std::shared_ptr<RishSefid> rishsefid = std::make_shared<RishSefid>();
        //rishsefid->setImage(QString::fromStdString(cardImages["RishSefid"]));
        mainDeck.push_back(rishsefid);
    }


    for (int i = 1; i <= 16; ++i)
    {
        std::shared_ptr<Matarsak> matarsak = std::make_shared<Matarsak>();
        //      matarsak->setImage(QString::fromStdString(cardImages["Matarsak"]));
        mainDeck.push_back(matarsak);
    }

    for (int i = 1; i <= 6; ++i)
    {
        std::shared_ptr<TablZan> tablzan = std::make_shared<TablZan>();
        //      matarsak->setImage(QString::fromStdString(cardImages["Matarsak"]));
        mainDeck.push_back(tablzan);
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

Player& Game::getPlayer(int index) {
    if (index < 0 || index >= players.size()) {
        throw std::out_of_range("Player index out of range");
    }
    return *players[index];
}

int Game::getPlayerCount() const{
    return playerCount;
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
    for (int i = 0 ; i < playerCount ; i++)
    {
        for (int j = 0; j < 10 + players[i]->getNumberOfOwnedProvinces(); j++)
        {
            if (!mainDeck.empty())
            {
                std::shared_ptr<Card> card = mainDeck.back(); // Get the top card from the main deck
                removeCardFromDeck(card, mainDeck);           // Remove the card from deck
                // Add the card to the player's deck
                if (card->getType() == "Purple")
                {
                    card->setindexOfOwner(i);
                    players[i]->addCardToPurpleHand(card);
                }
                else if (card->getType() == "Yellow")
                {
                    card->setindexOfOwner(i);
                    players[i]->addCardToYellowHand(card);
                }
            }
            else
            {
                qDebug() << "main deck is empty cant give cards to players";
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

void Game::updateTotalScore()
{
    // find better place to call this
    //saveThisGame();

    refreshEffects();
    for (auto &player : players)
    {
        int totalOnTable = 0;

        for (const auto &card : player->getYellowOnTable())
        {
            totalOnTable += card->getPoints();
        }
        for (const auto &card : player->getPurpleOnTable())
        {
            totalOnTable += card->getPoints();
        }
        player->setScore(totalOnTable);
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

void Game::endAllEffects()
{
    for (auto &player : players)
    {
        player->cancelEffects();
    }
}

void Game::startAllEffects()
{
    if(countRishSefid != 0)
    {
        for(int i =0 ; i < countRishSefid ;i++)
        {
            StartEffectOfRishSefid();
        }
        if (seasonSituation == "Winter")
        {
            startSeason("Winter");
            for (auto &player : players)
            {
                player->applyEffect();
            }
        }
        else if (seasonSituation == "Spring")
        {
            for (auto &player : players)
            {
                player->applyEffect();
            }
            startSeason("Spring");
        }
        else
        {
            for (auto &player : players)
            {
                player->applyEffect();
            }
        }
    }
    else
    {
        if (seasonSituation == "Winter")
        {
            startSeason("Winter");
            for (auto &player : players)
            {
                player->applyEffect();
            }
        }
        else if (seasonSituation == "Spring")
        {
            for (auto &player : players)
            {
                player->applyEffect();
            }
            startSeason("Spring");
        }
        else
        {
            for (auto &player : players)
            {
                player->applyEffect();
            }
        }

    }
}

void Game::refreshEffects()
{
    endAllEffects();
    reorderPurpleOnTable();
    startAllEffects();
}

void Game::StartEffectOfRishSefid()
{
    int max = getHighestYellowCardInGame();
    for (auto &player : players)
    {
        for (auto &yellowCard : player->getYellowOnTable())
        {
            if (yellowCard->getPoints() == max)
            {
                yellowCard->setPoints(0);
            }
        }
    }
}

void Game::setNeshaneJangOwner()
{
    static Player* defaultPlayer;
    std::vector<Player *> NeshaneJangOwners;
    int min = players[0]->getCountShirZan();

    for (auto &player : players)
    {
        if (player->getCountShirZan() < min)
        {
            min = player->getCountShirZan();
            NeshaneJangOwners.clear();
            NeshaneJangOwners.push_back(player);
        }
        else if (player->getCountShirZan() == min)
        {
            NeshaneJangOwners.push_back(player);
        }
    }

    if (NeshaneJangOwners.size() == 1)
    {
        NeshaneJangOwners[0]->setCanPutNeshaneJang(true);
        NeshaneJangOwner = NeshaneJangOwners[0];
    }
    else
    {
        NeshaneJangOwner = defaultPlayer;
    }
}


void Game::setNeshaneSolhOwner(int index)
{
    NeshaneSolhOwner = players[index];
}

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

void Game::setBattleStarter(const Player &player1)
{
    // Find the player
    for (int i = 0; i < playerCount; i++)
    {
        if (players[i]->getColor() == player1.getColor())
        {
            currentPlayerIndex = i;
            break;
        }
    }


}

void Game::setLastPlayerWhoPassed(int index)
{
    lastPlayerWhoPassed = players[index];
}

const Player *Game::getNeshaneSolhOwner() const
{
   return NeshaneSolhOwner;
}

const Player &Game::getPlayerWhoShouldStart()
{
    if (NeshaneJangOwner)
    {
        if (NeshaneJangOwner->getCanPutNeshaneJang())
        {
            qDebug() << "NeshaneJangOwner is the starting player";
            return *NeshaneJangOwner;
        }
    }

    if (lastWinner)
    {
        if (!lastWinner->getName().empty())
        {
            qDebug() << "lastWinner is the starting player";
            return *lastWinner;
        }
    }

    if (lastPlayerWhoPassed)
    {
        qDebug() << "lastPlayerWhoPassed is the starting player";
        return *lastPlayerWhoPassed;
    }

    qDebug() << "Error: No valid player found to start the battle!";
    throw std::runtime_error("No valid player found to start the battle.");
}


const Player &Game::findSmallestPlayer()
{
    if (players.empty())
    {
        static Player defaultPlayer; // Return a default player if no players are found
        return defaultPlayer;
    }

    std::vector<const Player *> smallestPlayers;
    int minAge = players[0]->getAge();

    for (const auto &player : players)
    {
        qDebug()<< QString::fromStdString(player->getName()) << " age  : "  << player->getAge();
        if (player->getAge() < minAge)
        {
            minAge = player->getAge();
            smallestPlayers.clear();
            smallestPlayers.push_back(player);
        }
        else if (player->getAge() == minAge)
        {
            smallestPlayers.push_back(player);
        }
    }

    // Seed the random number generator
    std::srand(std::time(0));

    // Randomly select one of the youngest players
    int randomIndex = std::rand() % smallestPlayers.size();

    return *(smallestPlayers[randomIndex]);
}


void Game::startSeason(const std::string userChoice)
{
    if (userChoice == "Winter")
    {
        // removeGameSeason("Spring");
        seasonSituation = "Winter";
        for (auto &changePlayer : players)
        {
            for (auto &yellowcards : changePlayer->getYellowOnTable())
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

        // removeGameSeason("Winter");
        seasonSituation = "Spring";

        int max = getHighestYellowCardInGame();
        for (auto &player : players)
        {
            for (auto &yellowCard : player->getYellowOnTable())
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

    }
}

void Game::endSeason(const std::string &userChoice)
{
    if (userChoice == "Winter" && seasonSituation == "Winter")
    {
        for (auto &player : players)
        {
            for (auto &yellowCard : player->getYellowOnTable())
            {
                yellowCard->setPoints(yellowCard->getNumberOnTheCard());
            }
        }
    }
    else if (userChoice == "Spring" && seasonSituation == "Spring")
    {
        for (auto &player : players)
        {
            for (auto &yellowCard : player->getYellowOnTable())
            {
                yellowCard->setPoints(yellowCard->getNumberOnTheCard());
            }
        }
    }
}

int Game::playPlayerCard(int playerIndex, const std::string& cardName) {
    //qDebug() << "playing card for player";
    //    if (playerIndex < 0 || playerIndex >= players.size()) {
    //        qDebug() << "invalid player index";
    //        return; // Invalid player index
    //    }
    qDebug() <<"playing card for" << QString::fromStdString(players[playerIndex]->getName());
    int situation{0};
    if(cardName == "Winter" || cardName == "Spring")
    {
        if(canStartSeason(cardName))
        {
            situation = players[playerIndex]->PlayThisCard(cardName);
            qDebug() <<"chanegd sit to ";
        }
        else
        {
            return 4;
        }
    }
    else
    {
        situation = players[playerIndex]->PlayThisCard(cardName);
    }


    // Handle result and update game state
    if (situation == -1) {
        nextTurn(); // Move to the next player's turn TODO:it should pass
        if(!anyPlayerCanPlay)
        {
            return 11; //the match has ended
        }
        else
        {
            return -1;
        }
    }
    else if (situation == 0) {
        // was not found so we are not going next player.
        nextTurn();
        return 0;
    }
    else if (situation == 1){ // Successfully played a card
        if(cardName != "Matarsak"){
            qDebug() << "card played successfully";
            nextTurn();
            return 1;
        }
        else
        {
            qDebug() << "card played matarsak successfully";
            return 1;
        }
    }
    else if (situation == 2){ // It is a season
        seasonSituation = cardName;
        nextTurn();
        return 2;
    }
    else if (situation == 4) //Can not be Played.
    {
        return 4;

    }
    else if (situation == 5) // It is RishSefid
    {
        countRishSefid++;
        setNeshaneSolhOwner(playerIndex);
        nextTurn();
        return 5;
    }
    else if (situation == 6) // It is ParchamDar
    {
        parchamDarIsPlayed = true;
        nextTurn(); // TODO:it should end game
        return 11; //the match has ended
    }
}

void Game::nextTurn() {

    int checkedPlayers = 0;

    while (checkedPlayers < playerCount) {
        currentPlayerIndex = (currentPlayerIndex  + 1) % playerCount;
        if (players[currentPlayerIndex]->canPlay())
        {
            qDebug() << "is turn of :" << currentPlayerIndex;
            return;
        }
        checkedPlayers++;
    }
}



std::vector<std::shared_ptr<Card>> Game::getPlayerYellowHand(int playerIndex) const {
    if (playerIndex >= 0 && playerIndex < players.size()) {
        return players[playerIndex]->getYellowHand();
    }
    return {};
}

std::vector<std::shared_ptr<Card>> Game::getPlayerPurpleHand(int playerIndex) const {
    if (playerIndex >= 0 && playerIndex < players.size()) {
        return players[playerIndex]->getPurpleHand();
    }
    return {};
}

std::vector<std::shared_ptr<Card>> Game::getPlayerYellowOnTable(int playerIndex) const {
    if (playerIndex >= 0 && playerIndex < players.size()) {
        return players[playerIndex]->getYellowOnTable();
    }
    return {};
}

std::vector<std::shared_ptr<Card>> Game::getPlayerPurpleOnTable(int playerIndex) const {
    if (playerIndex >= 0 && playerIndex < players.size()) {
        return players[playerIndex]->getPurpleOnTable();
    }
    return {};
}


void Game::setPlayerIndex(int playerIndex)
{
    currentPlayerIndex = playerIndex;
}

int Game::getPlayerIndex() const
{
    return currentPlayerIndex;
}

bool Game::getIsFirstRound() const
{
    return firstRound;
}

void Game::setIsFirstRound(bool situation)
{
    firstRound = situation;
}

bool Game::getAnyPlayerCanPlay() const
{
    return anyPlayerCanPlay;
}

void Game::updateAnyPlayerCanPlay()
{
    int count =0;
    for(const auto player : players)
    {
        if(player->canPlay() ==false)
        {
            count++;
        }
    }
    if(count == players.size())
    {
        anyPlayerCanPlay = false;
    }
    else
    {
        anyPlayerCanPlay = true;
    }
}

void Game::updatePlayersEligibility(int index)
{
    players[index]->updatePlayerEligibility(false);

    qDebug() << "updatePlayersEligibility";
}

void Game::setLastWinner(Player &winnerVal)
{
    lastWinner = &winnerVal;
}

int Game::checkThisBattleWinner(const std::string &province)
{

    int max{0};
    Player *winner = nullptr;
    // find max score
    for (auto &player : players)
    {
        if (player->getPoints() >= max)
        {
            max = player->getPoints();
            winner = player;
        }
    }
    int tieCounter{0};
    // count players with max score
    for (auto &player : players)
    {
        if (player->getPoints() == max)
        {
            tieCounter++;
        }
    }
    // if there are more than 1 max, its a tie
    if (tieCounter > 1)
    {
        return 0;
        //      std::cout << "The game has no winner, it's a tie." << std::endl;
    }
    else if (winner != nullptr)
    {
        //      std::cout << winner->getName() << " captured " << province << " with " << winner->getPoints() << " points." << std::endl;
        winner->addOwnedProvinces(province);
        battleCompleted  = "Yes";
        setLastWinner(*winner);
        return 1;
    }
    else
    {
        //        std::cout << "No winner could be determined." << std::endl;
        return 2;
    }
}

bool Game::winGame1()
{
    for (auto &player : players)
    {
        const auto &ownedProvinces = player->getOwnedProvinces();

        for (const auto &province : ownedProvinces)
        {
            const auto &adjacentProvinces = map.get_adjacent_provinces(province);
            int adjacentCount = 0;

            for (const auto &adjacentProvince : adjacentProvinces)
            {
                if (std::find(ownedProvinces.begin(), ownedProvinces.end(), adjacentProvince) != ownedProvinces.end())
                {
                    adjacentCount++;
                }
                if (adjacentCount >= 2)
                {
                    player->setWinStatus(true);
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
        if (player->getNumberOfOwnedProvinces() >= 5)
        {
            player->setWinStatus(true);
            return true;
        }
    }
    return false;
}

std::string Game::findWinner()
{
    qDebug() << "findWinner";
    for (auto player : players)
    {
        if (player->getWinStatus())
        {
            return player->getName();
        }
    }
}


int Game::handleMatarsakEffect(int playerIndex, const std::string& cardName) {

    std::shared_ptr<Card> targetCard = players[playerIndex]->removeCardFromYellowOnTable(cardName);

    if (targetCard) {
        players[playerIndex]->addCardToYellowHand(targetCard);
        nextTurn();
        return 1; // Success
    } else {
        return 0; // Card not found on the table
    }
}

std::string Game::toString() const {
    std::ostringstream oss;

    oss << battleCompleted << ",";
    // Basic game information
    oss << playerCount  << ",";
    oss << currentPlayerIndex << ",";
    oss << (anyPlayerCanPlay ? "Yes" : "No") << ",";
    oss << seasonSituation << ",";
    if (battleCompleted == "Yes")
    {
        oss << "None";
    }
    else
    {
        oss << battleIsOnThis ;
    }
    oss<<",";
    oss << neshaneSolhProvince  << ",";
    if(lastWinner){
        oss <<lastWinner->getColor()<< ",";
    }
    else oss << "None,";
    if(NeshaneSolhOwner){
        oss <<NeshaneJangOwner->getColor() <<",";
    }
    else oss << "None,";
    if(NeshaneJangOwner){
        oss <<NeshaneJangOwner->getColor() <<",";
    }
    else oss << "None,";
    if(lastPlayerWhoPassed){
        oss <<lastPlayerWhoPassed->getColor();
    }
    else oss << "None";
    oss << "\n";

    // Player details
    for (const auto &player : players) {
        if (player) {
            oss << player->toString() ;
        }
    }
    return oss.str();
}

void Game::saveThisGame(std::string filename)
{
    auto save = new Save();
    save->addGameToFile(this->toString() , filename);
}

int Game::loadFromFile(std::string filename)
{
    auto save = new Save();
    players.clear();
    save->loadGame(filename , players );
    auto savedCount = save->getplayerCount();
    setPlayersCount(savedCount);
    battleCompleted = save->getBattleCompleted();
    currentPlayerIndex = save->getCurrentPlayerIndex();
    anyPlayerCanPlay =( save->getAnyPlayerCanPlay() == "Yes" );
    battleIsOnThis = save->getBattleIsOnThis();
    neshaneSolhProvince = save->getNeshaneSolhProvince();
    seasonSituation = save->getSeasonSituation();

    auto lastWinnerColor        = save ->getLastWinnerColor();
    auto NeshaneJangOwnerColor = save->getNeshaneJangOwnerColor();
    auto NeshaneSolggOwnerColor= save ->getNeshaneSolhgOwnerColor();
    auto lastPlayerWhoPassedColor= save->getlastPlayerWhoPassedColor();

    for (auto player: players){
        if (player->getColor() == lastWinnerColor){
            lastWinner = player;
            break;
        }
        else {
            lastWinner = nullptr;
        }
    }

    for (auto player: players){
        if (player->getColor() == NeshaneJangOwnerColor){
            NeshaneJangOwner = player;
            break;
        }
        else {
            NeshaneJangOwner = nullptr;
        }
    }

    for (auto player: players){
        if (player->getColor() == NeshaneSolggOwnerColor){
            NeshaneSolhOwner = player;
            break;
        }
        else {
            NeshaneSolhOwner = nullptr;
        }
    }

    for (auto player: players){
        if (player->getColor() == lastPlayerWhoPassedColor){
            lastPlayerWhoPassed = player;
            break;
        }
        else {
            lastPlayerWhoPassed = nullptr;
        }
    }


    for(auto player : players)
    {
        qDebug() << QString::fromStdString( player->getName());
        qDebug() << "*****************************"
                    "**********************************"
                    "**********************************"
                    "************************************"
                    "********************************* why this does not worrk";

    }

    auto battleCompleted = save->getBattleCompleted();
    if (battleCompleted){
        qDebug() <<"im here in battle completed function ";
        return 1; // battle completed
    }
    qDebug() << "oh i think the battle is not completed";
    return 2 ; // battle not completed
}

void Game::gameFlusher()
{
    seasonSituation = "normal";
    neshaneSolhProvince = "None";
    anyPlayerCanPlay = true;
    parchamDarIsPlayed = false;
    NeshaneJangOwner = nullptr;
    NeshaneSolhOwner = nullptr;
    countRishSefid = 0;
    for (int i{0} ; i < playerCount ; i++)
    {
        players[i]->updatePlayerEligibility(true);
        // Move cards from table to burnt cards
        players[i]->flushTable();
        updateTotalScore();
        updateCardHoldersCount();
    }
}

void Game::setBattleCompleted(std::string val)
{
    battleCompleted = val ;
}

std::string Game::getBattleCompleted()
{
    return battleCompleted;
}

void Game::setBattleIsOnThis(std::string val)
{
    battleIsOnThis = val ;
}

std::string Game::getBattleIsOnThis()
{
    return battleIsOnThis;
}

void Game::setNeshaneSolhProvince(std::string province)
{
    neshaneSolhProvince = province;
}
std::string Game::getNeshaneSolhProvince() const
{
    return neshaneSolhProvince;
}

 Player* Game::WhosColorIsThis(std::string color) {
    for (auto *player : players){
        if (player->getColor() == color){
            return player;
        }
    }
        return nullptr ;
}

