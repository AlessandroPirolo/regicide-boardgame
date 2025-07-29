#include "../../include/card/card.hpp"
#include "../../include/utilities/utility.hpp"

Suit Card::getSuit() const {
  return suit;
}

void Card::setSuit(Suit suit) const {
  this->suit = suit;
}

Value Card::getValue() const {
  return value;
}

void Card::setValue(Value value) const {
  this->value = value;
}

bool Card::getIsEffect() const {
  return is_effect;
}

Card::Card(Suit suit, Value value, bool is_effect, Effect* effect) 
  : suit(suit), value(value), is_effect(is_effect), effect(effect), attack(int(value)) 
{}

Card::~Card() {}

Card::Card() 
  : suit(Suit::None), value(Value::None), is_effect(false), effect(nullptr)
{}

Card::Card(const Card &other)
  : suit(other.suit), value(other.value), is_effect(other.is_effect), effect(other.effect)
{}

bool Card::operator==(const Card& other) {
  return (other.suit == suit) && (other.value == value);
}

void Card::setIsEffect(bool val) const {
  is_effect = val;
}

Effect Card::getEffect() const {
  return *effect;
}

unsigned int Card::getAtk() const {
  return attack;
}

void Card::setAtk(unsigned int atk) const {
  attack = atk;
}

void Card::resetAtk() const {
  this->attack = int(this->value);
}
