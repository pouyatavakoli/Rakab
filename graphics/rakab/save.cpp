#include "save.h"
#include <fstream>
#include <QString>
#include <QDebug>

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


Save::Save() : numberOfGames(0) {}

int Save::getplayerCount()
{
    return playerCount;
}

// File saving logic
bool Save::addGameToFile(const std::string game) {
    std::string filename = "saved_games.txt";

    // Open file
    std::ofstream outFile(filename, std::ios::trunc);
    if (!outFile.is_open()) {
        qDebug() << "Could not open file for writing: " << QString::fromStdString(filename);
        return false; // Return false if the file couldn't be opened
    }

    outFile << game << "\n";

    outFile.close(); // Close the file
    qDebug() << "saved to file" ;
    return true; // Return true if writing was successful

}

bool Save::readMetaData(const std::string& line)
{
    std::stringstream ss(line);
    std::string token;

    try {
        // Read and trim the first token (battleCompleted)
        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);
        battleCompleted = (token == "Yes");
        qDebug() << "battle completed: " << QString::fromStdString(token);

        // Read and trim the second token (playerCount)
        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);
        qDebug() << "player count: " << QString::fromStdString(token);
        playerCount = std::stoi(token);

        // Read and trim the third token (currentPlayerIndex)
        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);
        currentPlayerIndex = std::stoi(token);
        qDebug() << "current index: " << QString::fromStdString(token);


        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);
        anyPlayerCanPlay = token;
        qDebug() << "any player can play: " << QString::fromStdString(token);

        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);
        seasonSituation = token;
        qDebug() << "seasonSituation : " << QString::fromStdString(token);

        std::getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);
        battleIsOnThis = token;
        qDebug() << "battleIsOn : " << QString::fromStdString(token);

        /*
        // Optionally, check if there are any extra tokens or trailing data
        std::getline(ss, token, ',');
        if (!token.empty() && token.find_first_not_of(" ") != std::string::npos) {
            throw std::runtime_error("Unexpected extra data after last field.");
        }
        */
    } catch (const std::exception& e) {
        qDebug() << "Error parsing metadata: " << QString::fromStdString(e.what());
        return false;
    }
    return true;
}





bool Save::readPlayerDetails(Player& player, const std::string& playerLine) {
    std::stringstream ss(playerLine);
    std::string token;

    try {
        std::getline(ss, token, ',');
        player.setName(token);
        qDebug() << "Player name set: " << QString::fromStdString(token);

        std::getline(ss, token, ',');
        player.setAge(std::stoi(token));
        qDebug() << "Player age set: " << QString::fromStdString(token);

        std::getline(ss, token, ',');
        player.setScore(std::stoi(token));
        qDebug() << "Player score set: " << QString::fromStdString(token);

        std::getline(ss, token, ',');
        player.setWinStatus(token == " Yes");
        qDebug() << "Player win status set: " << QString::fromStdString(token);

        std::getline(ss, token, ',');
        player.setCanPutNeshaneSolh(token == " Yes");
        qDebug() << "Player neshanSolh set: " << QString::fromStdString(token);

        std::getline(ss, token, ',');
        player.setCanPutNeshaneJang(token == " Yes");
        qDebug() << "Player neshanJang set: " << QString::fromStdString(token);

    } catch (const std::exception& e) {
        qDebug() << "Error parsing player details: " << QString::fromStdString(e.what());
        return false;
    }
    return true;
}

// Helper method to read province details
bool Save::readProvinceDetails(Player& player, std::ifstream& inputFile) {
    std::string line;
    if (std::getline(inputFile, line)) {
        try {
            line.erase(0, line.find_first_not_of(" "));
            line.erase(line.find_last_not_of(" ") + 1);
            numberOfProvinces = std::stoi(line);
            qDebug()<< "numberOfProvinces : " << numberOfProvinces;
            if (numberOfProvinces == 0){
                // burn the none line
                std::getline(inputFile, line);
            }

        }
        catch (const std::exception& e) {
            qDebug() << "Error parsing province " ;
            return false;
        }

        for (int j = 0; j < numberOfProvinces; j++) {
            if (!std::getline(inputFile, line)) {
                qDebug() << "Failed to read line from input file at iteration" << j;
                return false;
            }

            if (line == "None") {
                qDebug()<< "line was none";
                continue; // Skip this iteration if the line is "None"
            }

            std::stringstream cardStream(line);
            std::string token;

            if (!std::getline(cardStream, token, ',')) {
                qDebug() << "Error reading province name.";
                continue;
            }
            else{
                player.addOwnedProvinces(token);
                qDebug() << QString::fromStdString(token) ;
            }

        }
    }
    return true;
}



// Helper method to read card details and add them to the player
bool Save::readCardDetails(Player& player, std::ifstream& inputFile, const std::string& handType) {
    std::string line;
    if (std::getline(inputFile, line)) {
        try {
            line.erase(0, line.find_first_not_of(" "));
            line.erase(line.find_last_not_of(" ") + 1);
            cardCount = std::stoi(line);
            qDebug() << QString::fromStdString(handType) + " count: " << cardCount;
        } catch (const std::exception& e) {
            qDebug() << "Error parsing card count for " << QString::fromStdString(handType) << ": " << QString::fromStdString(e.what());
            return false;
        }

        for (int j = 0; j < cardCount; j++) {
            if (!std::getline(inputFile, line)) {
                qDebug() << "Failed to read line from input file at iteration" << j;
                return false;
            }

            if (line == "None") {
                continue; // Skip this iteration if the line is "None"
            }

            std::stringstream cardStream(line);
            std::string token, cardType;
            int index;

            if (!std::getline(cardStream, token, ',')) {
                qDebug() << "Error reading card type.";
                continue;
            }
            cardType = token;

            if (!std::getline(cardStream, token, ',')) {
                qDebug() << "Error reading card index.";
                continue;
            }
            try {
                index = std::stoi(token);
            } catch (const std::exception& e) {
                qDebug() << "Error converting card index: " << QString::fromStdString(e.what());
                continue;
            }

            auto card = createCard(cardType);
            if (card) {
                card->setindexOfOwner(index);
                if (handType == "YellowHand") {
                    player.addCardToYellowHand(card);
                    qDebug() << "Yellow card added to hand: " << QString::fromStdString(cardType);
                } else if (handType == "PurpleHand") {
                    player.addCardToPurpleHand(card);
                    qDebug() << "Purple card added to hand: " << QString::fromStdString(cardType);
                } else if (handType == "YellowTable") {
                    player.addCardToYellowOnTable(card);
                    qDebug() << "Yellow on table added: " << QString::fromStdString(cardType);
                } else if (handType == "PurpleTable") {
                    player.addCardToPurpleOnTable(card);
                    qDebug() << "Purple card added to table: " << QString::fromStdString(cardType);
                }
            } else {
                qDebug() << "Failed to create card of type: " << QString::fromStdString(cardType);
            }
        }
    }
    return true;
}

// Helper method to create card objects
std::shared_ptr<Card> Save::createCard(const std::string& cardType) {
    if (cardType == "Yellow1") return std::make_shared<Yellow1>();
    if (cardType == "Yellow2") return std::make_shared<Yellow2>();
    if (cardType == "Yellow3") return std::make_shared<Yellow3>();
    if (cardType == "Yellow4") return std::make_shared<Yellow4>();
    if (cardType == "Yellow5") return std::make_shared<Yellow5>();
    if (cardType == "Yellow6") return std::make_shared<Yellow6>();
    if (cardType == "Yellow10") return std::make_shared<Yellow10>();
    if (cardType == "TablZan") return std::make_shared<TablZan>();
    if (cardType == "ShirZan") return std::make_shared<ShirZan>();
    if (cardType == "Winter") return std::make_shared<Winter>();
    if (cardType == "Spring") return std::make_shared<Spring>();
    if (cardType == "Matarsak") return std::make_shared<Matarsak>();
    if (cardType == "ParchamDar") return std::make_shared<ParchamDar>();
    if (cardType == "RishSefid") return std::make_shared<RishSefid>();
    if (cardType == "ShahDokht") return std::make_shared<ShahDokht>();
    return nullptr;
}

// Main method to load the game from a file
void Save::loadGame(const std::string& fileName, std::vector<Player*>& players) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        qDebug() << "Failed to open file: " << QString::fromStdString(fileName);
        return;
    }

    std::string line;

    // Read the metadata line
    if (std::getline(inputFile, line)) {
        if (!readMetaData(line)) {
            qDebug() << "Failed to read metadata.";
            inputFile.close();
            return;
        }
    } else {
        qDebug() << "Failed to read metadata line.";
        inputFile.close();
        return;
    }

    int validPlayers = 0;
    for (int i = 0; i < playerCount; i++) {
        Player* player = new Player(); // Allocate a new Player
        std::string playerLine;

        if (std::getline(inputFile, playerLine)) {
            if (playerLine != "None" &&
                readPlayerDetails(*player, playerLine) &&
                readProvinceDetails(*player, inputFile) &&
                readCardDetails(*player, inputFile, "YellowHand") &&
                readCardDetails(*player, inputFile, "PurpleHand") &&
                readCardDetails(*player, inputFile, "YellowTable") &&
                readCardDetails(*player, inputFile, "PurpleTable"))
            {
                players.push_back(player); // Add valid player to the list
                validPlayers++;
            } else {
                players.push_back(player); // Add valid player to the list
                validPlayers++;
                //delete player; // Clean up if any of the checks fail
            }
        } else {
            players.push_back(player); // Add valid player to the list
            validPlayers++;
            //delete player; // Clean up if unable to read player line
        }
    }


    inputFile.close();
    qDebug() << "validPlayers count :  " << validPlayers ;
}

void Save::setSeasonSituation(std::string val)
{
    seasonSituation = val   ;
}

std::string Save::getSeasonSituation()
{
    return seasonSituation;
}

void Save::setBattleIsOnThis(std::string val)
{
    battleIsOnThis = val;
}

std::string Save::getBattleIsOnThis()
{
    return battleIsOnThis;
}

std::vector<Player*> Save::getPlayers()
{
    return players ;
}

std::vector<std::shared_ptr<Card> > Save::getMainDeck()
{
    return mainDeck ;
}




std::string Save::getNeshaneSolhgOwner()
{
    return neshaneSolhgOwner;
}

std::string Save::NgeteshaneJangOwner()
{
    return neshaneJangOwner ;
}

int Save::getCountRishSefid()
{
    return countRishSefid ;
}
bool Save::getBattleCompleted()
{
    return battleCompleted ;
}

