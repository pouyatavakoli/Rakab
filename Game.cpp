#include "Game.hpp"
#include "Interface.hpp"

Game::Game() : playerCount(0) {}

void Game::setPlayersCount(int PlayerCountVal)
{
    playerCount = PlayerCountVal;
}

void Game::run()
{
    Interface interface; // create interface for the game
    setPlayersCount(interface.getPlayersCountFromUser());  // how many players are gonna play
    players.resize(playerCount);

    // get players name , age , color
    for (Player &player : players)
    {
        int i = 0;
        player.setName(interface.getPlayersNameFromUser(i));
        player.setAge(interface.getPlayerAgeFromUser(i));
        // TODO: get color
        i++;
    }
}