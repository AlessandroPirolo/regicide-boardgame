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

Cards::Card::Card(Suit suit, Value value, bool is_effect, Effect::IEffect* effect) 
  : suit(suit), value(value), is_effect(is_effect), effect(effect) 
{

}

Cards::Card::~Card() {}

Cards::Card::Card() 
  : suit(Utility::Suit::None), value(Utility::Value::None), is_effect(false), effect(nullptr)
{}

Cards::Card::Card(const Card &others)
  : suit(others.suit), value(others.value), is_effect(others.is_effect), effect(others.effect)
{

}

void Cards::Card::setIsEffect(bool val) {
  is_effect = val;
}
