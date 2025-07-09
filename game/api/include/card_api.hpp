#ifndef CARDAPI_H
#define CARDAPI_H 

#include "../../game_logic/include/utilities/utility.hpp"

using namespace Utility;

namespace CardApi {
  struct Card {
    Suit suit;
    Value value;
  };
}

#endif 
