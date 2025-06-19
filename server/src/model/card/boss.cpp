#include "../../../include/model/card/boss.hpp"
#include "../../../include/model/utilities/utility.hpp"

using namespace Utility;

Bosses::Boss::Boss(Suit suit, Value value, bool is_effect, unsigned int life, unsigned int attack) 
  : Card(suit, value, is_effect), life(life), attack(attack)
{

}

Bosses::Boss::~Boss() {}

Bosses::Boss::Boss(const Boss &other)
  : Card(other), life(other.life), attack(other.attack)
{

}

void Bosses::Boss::setAttack(unsigned int attack) {
  this->attack = attack;
}

void Bosses::Boss::setLife(unsigned int life) {
  this->life = life;
}

unsigned int Bosses::Boss::getLife() const {
  return life;
} 

unsigned int Bosses::Boss::getAttack() const {
  return attack;
} 
