#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "boss.hpp"

namespace Games {
  class Game {
    public:
      Game();
      ~Game();
      void step1();
      void step2();
      void step3();
      void step4();

    private:
      std::list<Players::Player> players;
      std::list<Cards::Card> main_deck;
      std::list<Cards::Card> waste_heap;
      std::list<Bosses::Boss> boss_deck;
      Players::Player current_player;
      Bosses::Boss current_boss;
      unsigned int turn; 
      

  };
  
}

#endif
