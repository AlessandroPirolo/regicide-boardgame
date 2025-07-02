#include "../../../include/model/card/card.hpp"
#include "../../../include/model/utilities/utility.hpp"

using namespace Utility;

Suit Cards::Card::getSuit() const {
  return suit;
}

void Cards::Card::setSuit(Suit suit) {
  this->suit = suit;
}

Value Cards::Card::getValue() const {
  return value;
}

void Cards::Card::setValue(Value value) {
  this->value = value;
}

bool Cards::Card::getIsEffect() const {
  return is_effect;
}

Cards::Card::Card(Suit suit, Value value, bool is_effect, Effect::Effect* effect) 
  : suit(suit), value(value), is_effect(is_effect), effect(effect) 
{

}

Cards::Card::~Card() {}

Cards::Card::Card() 
  : suit(Utility::Suit::None), value(Utility::Value::None), is_effect(false), effect(nullptr)
{}

Cards::Card::Card(const Card &other)
  : suit(other.suit), value(other.value), is_effect(other.is_effect), effect(other.effect)
{}

bool Cards::Card::operator==(const Card& other) {
  return (other.suit == suit) && (other.value == value);
}

void Cards::Card::setIsEffect(bool val) {
  is_effect = val;
}

Effect::Effect Cards::Card::getEffect() const {
  return *effect;
}
