#include "Game.hpp"
#include "Interface.hpp"


Game::Game() : playerCount(0) {}

void Game::setPlayersCount(int PlayerCountVal)
{
    playerCount = PlayerCountVal;
}

void Game::run()
{
    Interface interface;
    setPlayersCount(interface.getPlayersCountFromUser());
    players.resize(playerCount);
    for (Player &player : players)
    {
        int i = 0;
        player.setName(interface.getPlayersNameFromUser(i));
        i++;
    }
}