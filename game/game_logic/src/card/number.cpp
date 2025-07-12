#include "../../include/card/number.hpp"

Number::Number(Suit suit, Value value, bool is_effect, Effect *effect) 
  : Card(suit, value, is_effect, effect)
{

}

Number::~Number() {}

Number::Number(const Number &other)
  : Card(other)
{

}
