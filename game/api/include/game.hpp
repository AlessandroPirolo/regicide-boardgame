#ifndef GAME_H
#define GAME_H

#include "../../game_logic/include/game/igame_status.hpp"

using namespace Status;

namespace Games {
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
  };
  
}

#endif
