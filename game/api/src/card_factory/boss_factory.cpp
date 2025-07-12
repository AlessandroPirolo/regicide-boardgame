#include "../../include/card_factory/boss_factory.hpp"
#include "../../../game_logic/include/utilities/utility.hpp"
#include "../../../game_logic/include/card/effect/ieffect.hpp"
#include "../../../game_logic/include/card/boss.hpp"

Card* BossFactory::create(unsigned int value, Suit suit) const {
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
  return new Boss(suit, Value(value), true, value*2, value, &effect);
    
}
