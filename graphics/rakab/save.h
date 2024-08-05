#ifndef SAVE_H
#define SAVE_H
#include "string"



class Save {
public:
    Save();

    //bool saveGame(const Game &game);
    int getNumberOfGames() const;
    bool addGameToFile(const std::string game);

private:
    int numberOfGames;
    //std::vector<Game> games;

};

#endif // SAVE_H
