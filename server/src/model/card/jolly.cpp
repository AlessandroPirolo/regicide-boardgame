#include "../../../include/model/card/jolly.hpp"
#include "../../../include/model/utilities/utility.hpp"
#include "../../../include/model/card/effect/ieffect.hpp"

using namespace Effect;

Jollies::Jolly::Jolly(IEffect* effect) : Cards::Card(Suit::None, Value::None, true, effect) {}
