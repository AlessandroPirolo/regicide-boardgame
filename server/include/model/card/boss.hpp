#ifndef BOSS_H
#define BOSS_H
#include "card.hpp"

using namespace Cards;

namespace Bosses {
  class Boss: public Card {
    public:
      Boss(Suit suit, Value value, bool is_effect, unsigned int life, unsigned int attack);
      ~Boss();
      Boss(const Boss &other);

      unsigned int getLife() const;
      unsigned int getAttack() const;
      void setLife(unsigned int life);
      void setAttack(unsigned int attack);

    private:
      unsigned int life;
      unsigned int attack;
  }; 
}


#endif
