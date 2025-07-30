#include "../include/game.hpp"
#include "../include/channel.hpp"
#include "../../game_logic/include/game/game_status.hpp"
#include "../../game_logic/include/card/boss.hpp"
#include <list>

Game::Game(GameStatus* status)
  : status(status) 
{}

Game::~Game() 
{}

void Game::step1() {
  std::list<Card> move = ch->recv();
  status->play(move);
}

void Game::step2() {
  status->resolveEffects();
}
  
void Game::step3() {
  status->attack();
}

void Game::step4() {
  if (!status->defend(*this->ch))
  {
    //lost
  }
}

bool Game::won() {
  return status->won();
}

void Game::play() {
  while (!won()) 
  {
    step1();
    step2();
    step3();
    if (status->getCurrentBoss().getLife() == 0) 
    {
      if (!won()) status->nextBoss();
    }
    else 
    {
      step4();
      status->nextPlayer();
    }
  }

}
