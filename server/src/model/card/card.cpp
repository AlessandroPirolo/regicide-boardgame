#include "../../../include/model/card/card.hpp"
#include "../../../include/model/utilities/utility.hpp"

using namespace Utility;

Suit Cards::Card::getSuit() const {
  return suit;
}

Value Cards::Card::getValue() const {
  return value;
}

bool Cards::Card::getIsEffect() const {
  return is_effect;
}

Cards::Card::Card(Suit suit, Value value, bool is_effect) 
  : suit(suit), value(value), is_effect(is_effect) 
{

}

Cards::Card::~Card() {}

Cards::Card::Card(const Card &others)
  : suit(others.suit), value(others.value), is_effect(others.is_effect)
{

}
