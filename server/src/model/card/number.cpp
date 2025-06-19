#include "../../../include/model/card/number.hpp"
#include "../../../include/model/utilities/utility.hpp"
#include "../../../include/model/game/gameStatus.hpp"

using namespace Utility;
using namespace Status;

Numbers::Number::Number(Suit suit, Value value, bool is_effect) 
  : Card(suit, value, is_effect)
{

}

Numbers::Number::~Number() {}

Numbers::Number::Number(const Number &other)
  : Card(other)
{

}
