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

void Save::loadGame()
{
    std::string filename = "saved_games.txt";

    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        qDebug() << "Could not open file for reading: " << QString::fromStdString(filename) ;
        return; // Handle error
    }

    std::string line;

    // Read Players
    while (std::getline(inFile, line) && !line.empty()) {
        std::shared_ptr<Player> player ;
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ','); battleCompleted = token ;
        /*

        // Split by comma
        std::getline(ss, token, ','); player.setName(token); // Player Name
        std::getline(ss, token, ','); player.setAge(std::stoi(token)) ; // Age
        std::getline(ss, token, ','); player.setScore(std::stoi(token)) ; // Total Score
        std::getline(ss, token, ','); // Win Status
        if (token == "Yes") {
                player.setWinStatus(true);
            } else {
                player.setWinStatus(false);

        std::getline(ss, token, ','); player.canPutNeshaneJang = (token == "Yes"); // Can Put Neshane Jang
        std::getline(ss, token, ','); player.dominatedAreas = token; // Dominated Areas
        std::getline(ss, token, ','); player.yellowCardsOnTable = std::stoi(token); // Yellow Cards on Table
        std::getline(ss, token, ','); player.purpleCardsOnTable = std::stoi(token); // Purple Cards on Table
        std::getline(ss, token, ','); player.yellowCardsInHand = std::stoi(token); // Yellow Cards in Hand
        std::getline(ss, token); player.purpleCardsInHand = std::stoi(token); // Purple Cards in Hand


        */
        players.push_back(player);
    }

    // Read Main Deck
    /*
    if (std::getline(inFile, line) && line == "Main Deck:") {
        while (std::getline(inFile, line) && !line.empty()) {
            Card card;
            std::stringstream ss(line);
            std::string token;

            // Split by comma
            std::getline(ss, token, ','); card.name = token.substr(10); // Card Name
            std::getline(ss, token, ','); card.type = token.substr(6); // Type
            std::getline(ss, token, ','); card.number = std::stoi(token.substr(8)); // Number
            std::getline(ss, token, ','); card.points = std::stoi(token.substr(8)); // Points
            std::getline(ss, token); card.ownerIndex = std::stoi(token.substr(15)); // Owner Index

            mainDeck.push_back(card);
        }
    }
    */
    // Read Other Game State Information
    while (std::getline(inFile, line)) {
        if (line.find("Last Winner:") == 0) {
            lastWinner = line.substr(13); // Extract Last Winner
        } else if (line.find("Neshane Solhg Owner:") == 0) {
            neshaneSolhgOwner = line.substr(21); // Extract Neshane Solhg Owner
        } else if (line.find("Neshane Jang Owner:") == 0) {
            neshaneJangOwner = line.substr(20); // Extract Neshane Jang Owner
        } else if (line.find("Count Rish Sefid:") == 0) {
            countRishSefid = std::stoi(line.substr(17)); // Extract Count Rish Sefid
        }
    }

    inFile.close(); // Close the file
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
