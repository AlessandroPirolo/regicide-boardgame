#ifndef NUMBER_H
#define NUMBER_H
#include "card.hpp"

using namespace Cards;

namespace Numbers {
  class Number: public Card {
    public:
      Number(Suit suit, Value value, bool is_effect);
      ~Number();
      Number(const Number &other);

    private:
  }; 
}


#endif
