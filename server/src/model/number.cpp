#include "../../include/model/number.hpp"
#include "../../include/model/utility.hpp"

using namespace Utility;

Number::Number::Number(Suit suit, Value value, bool is_effect) 
  : Card(suit, value, is_effect)
{

}

Number::Number::~Number() {}

Number::Number::Number(const Number &other)
  : Card(other)
{

}

void Number::Number::effect() {}
