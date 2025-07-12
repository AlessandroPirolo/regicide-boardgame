#include "../../include/card_factory/jolly_factory.hpp"
#include "../../../game_logic/include/utilities/utility.hpp"
#include "../../../game_logic/include/card/effect/ieffect.hpp"
#include "../../../game_logic/include/card/jolly.hpp"

Card* JollyFactory::create(unsigned int value, Suit suit) const {
  Effect effect = {TypeEffect::NullEffect, value};
  return new Jolly(&effect);
    
}
