#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include "../player/player.hpp"
#include "../card/boss.hpp"
#include "igame_status.hpp"

namespace Status {
  class GameStatus: public IGameStatus {
    public:
      virtual void draw() override;
      virtual void decreaseAtk() override;
      virtual void doubleAtk() override;
      virtual void nullifyEfct() override;
      virtual void shuffle() override;

    private:
      std::list<Players::Player> players;
      std::list<Cards::Card> main_deck;
      std::list<Cards::Card> waste_heap;
      std::list<Bosses::Boss> boss_deck;
      Players::Player current_player;
      std::list<Cards::Card> cards_played;
      Bosses::Boss current_boss;
      unsigned int turn; 
  };
}

#endif
