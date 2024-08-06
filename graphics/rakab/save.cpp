#include "save.h"
#include <fstream>
#include <QString>
#include <QDebug>

Save::Save() : numberOfGames(0) {}

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

            auto player = std::make_shared<Player>();
            std::stringstream ss(playerLine);
            std::string token;

            // Read player details
            std::getline(ss, token, ',');
            player->setName(token);
            qDebug() << "Player name set: " << QString::fromStdString(token);

            std::getline(ss, token, ',');
            player->setAge(std::stoi(token));
            qDebug() << "Player age set: " << QString::fromStdString(token);

            std::getline(ss, token, ',');
            player->setScore(std::stoi(token));
            qDebug() << "Player score set: " << QString::fromStdString(token);

            std::getline(ss, token, ',');
            player->setWinStatus(token == "Yes");
            qDebug() << "Player win status set: " << QString::fromStdString(token);

            std::getline(ss, token, ',');
            player->setCanPutNeshaneJang(token == "Yes");
            qDebug() << "Player nehsanJang set: " << QString::fromStdString(token);

            // Push the shared pointer to the players vector
            players.push_back(player);
        }
    }

    inputFile.close(); // Close the file after reading
}

std::vector<std::shared_ptr<Player> > Save::getPlayers()
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
