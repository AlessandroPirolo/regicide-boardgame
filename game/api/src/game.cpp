#include "../include/game.hpp"
#include <list>

using namespace Status;

Game::Game(IGameStatus* status)
  : status(status) 
{}

Game::~Game() 
{}

void Game::step1() {
  std::list<Cards::Card> move = this->ch->recv();
  this->status->play(move);
}

void Game::step2() {

}
  
void Game::step3() {

}

void Game::step4() {

}

void Game::play() {
  // wait for a player move
  
  while (true) 
  {
    step1();
    step2();
  }

}
