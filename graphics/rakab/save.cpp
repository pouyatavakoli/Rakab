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

void Save::loadGame() {
    std::string filename = "saved_games.txt";
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        qDebug() << "Error opening file!";
        return; // Exit if the file cannot be opened
    }

    std::string line;
    // Read the first line for battle completion status and other metadata
    if (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string token;

        // first line of file :
        // Read the first token for battle completion status
        std::getline(ss, token, ',');
        battleCompleted = token;
        qDebug() << "Battle completed: " << QString::fromStdString(battleCompleted);

        std::getline(ss, token, ',');
        playerCount = std::stoi(token); // Correctly convert string to integer
        qDebug() << "Player count: " << playerCount;

        std::getline(ss, token, ',');
        currentPlayerIndex = std::stoi(token);
        qDebug() << "Current player index: " << currentPlayerIndex;

        std::getline(ss, token, ',');
        anyPlayerCanPlay = token;  // Yes or No
        qDebug() << "Any player can play: " << QString::fromStdString(anyPlayerCanPlay);
    }

    // Read player data
    for (int i = 0; i < playerCount; i++) {
        std::string playerLine;
        if (std::getline(inputFile, playerLine)) {
            if (playerLine == "None") {
                continue; // Skip lines that are just "None"
            }

            //auto player = std::make_shared<Player>();
            Player player;
            std::stringstream ss(playerLine);
            std::string token;

            // Read player details
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

            if (std::getline(inputFile, line)) {
                    try {
                        numberOfProvinces = std::stoi(line);
                        qDebug() << "numberOfProvinces: " << numberOfProvinces;
                    } catch (const std::invalid_argument &e) {
                        qDebug() << "Invalid argument for numberOfProvinces: " << QString::fromStdString(line);
                    } catch (const std::out_of_range &e) {
                        qDebug() << "Out of range error for numberOfProvinces: " << QString::fromStdString(line);
                    }
                }

                if (std::getline(inputFile, line)) {
                    std::istringstream ss(line);
                    for (int i = 0; i < numberOfProvinces; ++i) {
                        std::getline(ss, token, ',');
                        player.addOwnedProvinces(token);
                        qDebug() << "Player dominated area set: " << QString::fromStdString(token);
                    }
                }



            // Read yellow hand details
            if (std::getline(inputFile, line)) {
                try {
                    yellowCardsCount = std::stoi(line);
                    qDebug() << "yellowCardsCount: " << yellowCardsCount;
                } catch (const std::invalid_argument& e) {
                    qDebug() << "Invalid argument for yellowCardsCount: " << QString::fromStdString(line);
                    continue;
                } catch (const std::out_of_range& e) {
                    qDebug() << "Out of range error for yellowCardsCount: " << QString::fromStdString(line);
                    continue;
                }

                for (int j = 0; j < yellowCardsCount; j++) {
                    if (std::getline(inputFile, line)) {
                        if (line == "None") {
                            continue;
                        }

                        std::stringstream cardStream(line);
                        std::getline(cardStream, token, ',');
                        auto cardType = token;

                        std::getline(cardStream, token, ',');
                        int index = std::stoi(token);

                        std::shared_ptr<Card> card;
                        if (cardType == "Yellow1") card = std::make_shared<Yellow1>();
                        else if (cardType == "Yellow2") card = std::make_shared<Yellow2>();
                        else if (cardType == "Yellow3") card = std::make_shared<Yellow3>();
                        else if (cardType == "Yellow4") card = std::make_shared<Yellow4>();
                        else if (cardType == "Yellow5") card = std::make_shared<Yellow5>();
                        else if (cardType == "Yellow6") card = std::make_shared<Yellow6>();
                        else if (cardType == "Yellow10") card = std::make_shared<Yellow10>();

                        if (card) {
                            card->setindexOfOwner(index);
                            player.addCardToYellowHand(card);
                            qDebug() << "Yellow card added to hand: " << QString::fromStdString(cardType);
                        }
                    }
                }
            }

            // Read purple hand details
            if (std::getline(inputFile, line)) {
                try {
                    purpleCardsCount = std::stoi(line);
                    qDebug() << "purpleCardsCount: " << purpleCardsCount;
                } catch (const std::invalid_argument& e) {
                    qDebug() << "Invalid argument for purpleCardsCount: " << QString::fromStdString(line);
                    continue;
                } catch (const std::out_of_range& e) {
                    qDebug() << "Out of range error for purpleCardsCount: " << QString::fromStdString(line);
                    continue;
                }

                for (int j = 0; j < purpleCardsCount; j++) {
                    if (std::getline(inputFile, line)) {
                        if (line == "None") {
                            continue;
                        }

                        std::stringstream cardStream(line);
                        std::getline(cardStream, token, ',');
                        auto cardType = token;

                        std::getline(cardStream, token, ',');
                        int index = std::stoi(token);

                        std::shared_ptr<Card> card;
                        if (cardType == "TablZan") card = std::make_shared<TablZan>();
                        else if (cardType == "ShirZan") card = std::make_shared<ShirZan>();
                        else if (cardType == "Winter") card = std::make_shared<Winter>();
                        else if (cardType == "Spring") card = std::make_shared<Spring>();
                        else if (cardType == "Matarsak") card = std::make_shared<Matarsak>();
                        else if (cardType == "ParchamDar") card = std::make_shared<ParchamDar>();
                        else if (cardType == "RishSefid") card = std::make_shared<RishSefid>();

                        if (card) {
                            card->setindexOfOwner(index);
                            player.addCardToPurpleHand(card);
                            qDebug() << "Purple card added to hand: " << QString::fromStdString(cardType);
                        }
                    }
                }
            }

            // Read yellow table details
            if (std::getline(inputFile, line)) {
                try {
                    yellowCardsCount = std::stoi(line);
                    qDebug() << "yellowCardsCount: " << yellowCardsCount;
                } catch (const std::invalid_argument& e) {
                    qDebug() << "Invalid argument for yellowCardsCount: " << QString::fromStdString(line);
                    continue;
                } catch (const std::out_of_range& e) {
                    qDebug() << "Out of range error for yellowCardsCount: " << QString::fromStdString(line);
                    continue;
                }

                for (int j = 0; j < yellowCardsCount; j++) {
                    if (std::getline(inputFile, line)) {
                        if (line == "None") {
                            continue;
                        }

                        std::stringstream cardStream(line);
                        std::getline(cardStream, token, ',');
                        auto cardType = token;

                        std::getline(cardStream, token, ',');
                        int index = std::stoi(token);

                        std::shared_ptr<Card> card;
                        if (cardType == "Yellow1") card = std::make_shared<Yellow1>();
                        else if (cardType == "Yellow2") card = std::make_shared<Yellow2>();
                        else if (cardType == "Yellow3") card = std::make_shared<Yellow3>();
                        else if (cardType == "Yellow4") card = std::make_shared<Yellow4>();
                        else if (cardType == "Yellow5") card = std::make_shared<Yellow5>();
                        else if (cardType == "Yellow6") card = std::make_shared<Yellow6>();
                        else if (cardType == "Yellow10") card = std::make_shared<Yellow10>();

                        if (card) {
                            card->setindexOfOwner(index);
                            player.addCardToYellowOnTable(card);
                            qDebug() << "Yellow on table added : " << QString::fromStdString(cardType);
                        }
                    }
                }
            }

            // Read purple table details
            if (std::getline(inputFile, line)) {
                try {
                    purpleCardsCount = std::stoi(line);
                    qDebug() << "purpleCardsCount: " << purpleCardsCount;
                } catch (const std::invalid_argument& e) {
                    qDebug() << "Invalid argument for purpleCardsCount: " << QString::fromStdString(line);
                    continue;
                } catch (const std::out_of_range& e) {
                    qDebug() << "Out of range error for purpleCardsCount: " << QString::fromStdString(line);
                    continue;
                }

                for (int j = 0; j < purpleCardsCount; j++) {
                    if (std::getline(inputFile, line)) {
                        if (line == "None") {
                            continue;
                        }

                        std::stringstream cardStream(line);
                        std::getline(cardStream, token, ',');
                        auto cardType = token;

                        std::getline(cardStream, token, ',');
                        int index = std::stoi(token);

                        std::shared_ptr<Card> card;
                        if (cardType == "TablZan") card = std::make_shared<TablZan>();
                        else if (cardType == "ShirZan") card = std::make_shared<ShirZan>();
                        else if (cardType == "Winter") card = std::make_shared<Winter>();
                        else if (cardType == "Spring") card = std::make_shared<Spring>();
                        else if (cardType == "Matarsak") card = std::make_shared<Matarsak>();
                        else if (cardType == "ParchamDar") card = std::make_shared<ParchamDar>();
                        else if (cardType == "RishSefid") card = std::make_shared<RishSefid>();

                        if (card) {
                            card->setindexOfOwner(index);
                            player.addCardToPurpleOnTable(card);
                            qDebug() << "Purple on table added : " << QString::fromStdString(cardType);
                        }
                    }
                }
            }

            players.push_back(&player);
        }
    }
    inputFile.close(); // Close the file after reading
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

std::string Save::getBattleCompleted()
{
    return battleCompleted ;
}
