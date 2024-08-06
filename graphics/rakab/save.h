#ifndef SAVE_H
#define SAVE_H

#include <vector>
#include <string>
#include "card.h"
#include"player.h"

class Save {
public:

    Save();
    //bool saveGame(const Game &game);
    int getNumberOfGames() const;
    bool addGameToFile(const std::string game);
    void loadGame();


    std::vector<std::shared_ptr<Player>> getPlayers() ;
    std::vector<std::shared_ptr<Card>> getMainDeck() ;


    std::string getNeshaneSolhgOwner();
    std::string NgeteshaneJangOwner();
    int getCountRishSefid();
    std::string getBattleCompleted();


private:
    std::string battleCompleted ;
    int playerCount;
    int numberOfGames;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    std::string lastWinner;
    std::string neshaneSolhgOwner;
    std::string neshaneJangOwner;
    int countRishSefid;
    int currentPlayerIndex;
    std::string anyPlayerCanPlay;

};
//std::vector<Game> games;


#endif // SAVE_H
