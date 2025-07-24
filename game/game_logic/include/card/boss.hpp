#ifndef BOSS_H
#define BOSS_H
#include "card.hpp"

class Boss: public Card {
  public:
    Boss(Suit suit, Value value, 
        bool is_effect, unsigned int life, 
        Effect* effect);
    ~Boss();
    Boss(const Boss &other);
    Boss();

    unsigned int getLife() const;
    void decreaseLife(unsigned int amount) const;
    Boss& operator=(const Boss& other);

  private:
    mutable unsigned int life;
  }; 

#endif
