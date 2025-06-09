#include "../../include/model/boss.hpp"
#include "../../include/model/utility.hpp"

using namespace Utility;

Boss::Boss::Boss(Suit suit, Value value, bool is_effect, unsigned int life, unsigned int attack) 
  : Card(suit, value, is_effect), life(life), attack(attack)
{

}

Boss::Boss::~Boss() {}

Boss::Boss::Boss(const Boss &other)
  : Card(other), life(other.life), attack(other.attack)
{

}

void Boss::Boss::effect() {}

void Boss::Boss::setAttack(unsigned int attack) {
  this->attack = attack;
}

void Boss::Boss::setLife(unsigned int life) {
  this->life = life;
}

unsigned int Boss::Boss::getLife() const {
  return life;
} 

unsigned int Boss::Boss::getAttack() const {
  return attack;
} 
