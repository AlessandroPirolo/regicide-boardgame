#include "../include/game.hpp"
#include "../include/channel.hpp"
#include "../../game_logic/include/game/game_status.hpp"
#include <list>


Game::Game(GameStatus* status)
  : status(status) 
{}

Game::~Game() 
{}

void Game::step1() {
  std::list<Card> move = this->ch->recv();
  this->status->play(move);
}

void Game::step2() {
  this->status->resolveEffects();
}
  
void Game::step3() {
  this->status->attack();
}

void Game::step4() {
  this->status->defend();
}

bool Game::won() {
  return this->status->won();
}

void Game::play() {
  while (!won()) 
  {
    step1();
    step2();
    step3();
    if (!won()) step4();
  }
}
