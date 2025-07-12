#include "../../include/card_factory/number_factory.hpp"
#include "../../../game_logic/include/utilities/utility.hpp"
#include "../../../game_logic/include/card/effect/ieffect.hpp"
#include "../../../game_logic/include/card/number.hpp"

Card* NumberFactory::create(unsigned int value, Suit suit) const {
  Effect effect;
  switch (suit) { 
    case Suit::Hearts:
      effect = {TypeEffect::Shuffle, value};
    case Suit::Diamonds:
      effect = {TypeEffect::Draw, value};
    case Suit::Clubs:
      effect = {TypeEffect::DoubleAtk, value};
    case Suit::Spades:
      effect = {TypeEffect::DecreaseAtk, value};
    case Suit::None:
      effect = {TypeEffect::NullEffect, value};
  }
  return new Number(suit, Value(value), true, &effect);
    
}
