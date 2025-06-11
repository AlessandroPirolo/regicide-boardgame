#include "../../include/model/number.hpp"
#include "../../include/model/utility.hpp"

using namespace Utility;

Numbers::Number::Number(Suit suit, Value value, bool is_effect) 
  : Card(suit, value, is_effect)
{

}

Numbers::Number::~Number() {}

Numbers::Number::Number(const Number &other)
  : Card(other)
{

}

void Numbers::Number::effect() {}
