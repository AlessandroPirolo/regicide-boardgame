#include "../../../include/model/game/game.hpp"

using namespace Games;
using namespace Status;

Game::Game(IGameStatus* status)
  : status(status) 
{}

Game::~Game() 
{}

void Game::step1() {
  
}

void Game::play() {
  // wait for a player move
  status->play();

}
