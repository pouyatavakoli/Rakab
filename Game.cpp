#include "Game.hpp"

Game::Game() : playerCount(0) {}

void Game::setPlayersCount(int PlayerCountVal)
{
    playerCount = PlayerCountVal;
}

void Game::setPlayersName(std::string nameVal)
{
    for (Player &player : Players)
    {
        player.setName(nameVal);
    }
}
