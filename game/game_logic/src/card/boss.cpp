#include "../../include/card/boss.hpp"
#include "../../include/utilities/utility.hpp"

Boss::Boss(Suit suit, Value value, 
    bool is_effect, unsigned int life, 
    unsigned int attack, Effect* effect) 
  : Card(suit, value, is_effect, effect), life(life), attack(attack)
{}

Boss::~Boss() {}

Boss::Boss() 
  : Card(), life(0), attack(0)
{}

Boss::Boss(const Boss &other)
  : Card(other), life(other.life), attack(other.attack)
{}

Boss& Boss::operator=(const Boss& other) {
  if (this != &other) {
    life = other.life;
    attack = other.attack;
    setValue(other.getValue());
    setSuit(other.getSuit());
  }
  return *this;
}

void Boss::setAttack(unsigned int attack) {
  this->attack = attack;
}

void Boss::setLife(unsigned int life) {
  this->life = life;
}

unsigned int Boss::getLife() const {
  return life;
} 

unsigned int Boss::getAttack() const {
  return attack;
} 
