#ifndef BOSS_H
#define BOSS_H
#include "card.hpp"
#include "effect/ieffect.hpp"

using namespace Cards;
using namespace Effect;

namespace Bosses {
  class Boss: public Card {
    public:
      Boss(Suit suit, Value value, bool is_effect, unsigned int life, unsigned int attack, IEffect* effect);
      ~Boss();
      Boss(const Boss &other);
      Boss();

      unsigned int getLife() const;
      unsigned int getAttack() const;
      void setLife(unsigned int life);
      void setAttack(unsigned int attack);
      Boss& operator=(const Boss& other);

    private:
      unsigned int life;
      unsigned int attack;
  }; 
}


#endif
