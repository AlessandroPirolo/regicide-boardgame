#ifndef IGAMESTATUS_H
#define IGAMESTATUS_H

#include "../card/boss.hpp"
#include <list>

namespace Status {
  class IGameStatus {
    public:
      virtual void draw(unsigned int amount) = 0;
      virtual void shuffle(unsigned int amount) = 0;
      virtual void decreaseAtk(unsigned int amount) = 0;
      virtual void doubleAtk(unsigned int amount) = 0;
      virtual void nullifyEfct() = 0;
      virtual void play(std::list<Cards::Card> cards) = 0; 
  };
}

#endif // !IGAMESTATUS_H

