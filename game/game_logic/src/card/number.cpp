#include "../../../include/model/card/number.hpp"

using namespace Utility;

Numbers::Number::Number(Suit suit, Value value, bool is_effect, Effect::Effect *effect) 
  : Card(suit, value, is_effect, effect)
{

}

Numbers::Number::~Number() {}

Numbers::Number::Number(const Number &other)
  : Card(other)
{

}
