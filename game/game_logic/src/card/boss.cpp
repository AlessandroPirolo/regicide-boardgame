#include "../../include/card/boss.hpp"
#include "../../include/utilities/utility.hpp"

Boss::Boss(Suit suit, Value value, 
    bool is_effect, unsigned int life, 
    Effect* effect) 
  : Card(suit, value, is_effect, effect), life(life)
{}

Boss::~Boss() {}

Boss::Boss() 
  : Card(), life(0)
{}

Boss::Boss(const Boss &other)
  : Card(other), life(other.life)
{}

Boss& Boss::operator=(const Boss& other) {
  if (this != &other) {
    life = other.life;
    setValue(other.getValue());
    setSuit(other.getSuit());
  }
  return *this;
}

void Boss::decreaseLife(unsigned int amount) const {
  this->life -= amount;
}

unsigned int Boss::getLife() const {
  return life;
}  
