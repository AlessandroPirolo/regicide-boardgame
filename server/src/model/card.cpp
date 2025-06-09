#include "../../include/model/card.hpp"
#include "../../include/model/utility.hpp"

using namespace Utility;

Suit Card::Card::getSuit() const {
  return suit;
}

Value Card::Card::getValue() const {
  return value;
}

bool Card::Card::getIsEffect() const {
  return is_effect;
}

Card::Card::Card(Suit suit, Value value, bool is_effect) 
  : suit(suit), value(value), is_effect(is_effect) 
{

}

Card::Card::~Card() {}

Card::Card::Card(const Card &others)
  : suit(others.suit), value(others.value), is_effect(others.is_effect)
{

}
