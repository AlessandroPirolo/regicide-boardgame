#ifndef NUMBER_H
#define NUMBER_H
#include "card.hpp"
#include "utility.hpp"

using namespace Card;
using namespace Utility;

namespace Number {
  class Number: public Card {
    public:
      Number(Suit suit, Value value, bool is_effect);
      ~Number();
      Number(const Number &other);

    private:
  }; 
}


#endif
