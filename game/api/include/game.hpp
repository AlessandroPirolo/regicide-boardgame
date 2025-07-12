#ifndef GAME_H
#define GAME_H

#include "../../game_logic/include/game/igame_status.hpp"
#include "../include/channel.hpp"

using namespace Status;

class Game {
  public:
    Game(IGameStatus *status);
    ~Game();
    void play();

  private:
    void step1();
    void step2();
    void step3();
    void step4();

    IGameStatus *status;
    Channels::Channel<Cards::Card> *ch;
};
#endif
