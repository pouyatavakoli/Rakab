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

    int getplayerCount();
    int getNumberOfGames() const;
    bool addGameToFile(const std::string game);


    std::vector<Player*> getPlayers() ;
    std::vector<std::shared_ptr<Card>> getMainDeck() ;


    std::string getNeshaneSolhgOwner();
    std::string NgeteshaneJangOwner();
    int getCountRishSefid();
    bool getBattleCompleted();

    bool readMetaData(const std::string& playerLine);
    bool readPlayerDetails(Player &player, const std::string &playerLine);
    bool readProvinceDetails(Player &player, std::ifstream &inputFile);
    bool readCardDetails(Player &player, std::ifstream &inputFile, const std::string &handType);
    std::shared_ptr<Card> createCard(const std::string &cardType);
    void loadGame(const std::string &fileName, std::vector<Player *> &players);
private:
    bool battleCompleted ;
    int  playerCount;
    int  numberOfGames;
    std::vector<Player*> players;
    std::vector<std::shared_ptr<Card>> mainDeck;
    std::string lastWinner;
    std::string neshaneSolhgOwner;
    std::string neshaneJangOwner;
    int countRishSefid;
    int currentPlayerIndex;
    std::string anyPlayerCanPlay;

    int numberOfProvinces ;

    int cardCount ;

};
//std::vector<Game> games;


#endif // SAVE_H
