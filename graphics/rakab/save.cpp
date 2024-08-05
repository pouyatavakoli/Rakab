#include "save.h"
#include <fstream>
#include <QString>
#include <QDebug>

Save::Save() : numberOfGames(0) {}

// Save the game and add it to the internal list
/*
bool Save::saveGame(const Game &game) {
    // Save the game to the file and in the internal list
    if (addGameToFile(game)) {
        games.push_back(game);
        numberOfGames++;
        return true; // Return true if saving was successful
    }
    return false; // Return false if saving failed
}

// Returns the number of saved games
int Save::getNumberOfGames() const {
    return numberOfGames;
}
*/

// File saving logic
bool Save::addGameToFile(const std::string game) {
    std::string filename = "saved_games.txt";

    // Open file in append mode
    std::ofstream outFile(filename, std::ios::trunc);
    if (!outFile.is_open()) {
        qDebug() << "Could not open file for writing: " << QString::fromStdString(filename);
        return false; // Return false if the file couldn't be opened
    }

    outFile << game << "\n"; // Assuming game.toString() returns a string representation of the game

    outFile.close(); // Close the file
    qDebug() << "saved to file" ;
    return true; // Return true if writing was successful

}
