#ifndef NUMBER_H
#define NUMBER_H
#include "card.hpp"
#include "utility.hpp"

using namespace Cards;
using namespace Utility;

namespace Numbers {
  class Number: public Card {
    public:
      Number(Suit suit, Value value, bool is_effect);
      ~Number();
      Number(const Number &other);
      virtual void effect() override;

    private:
  }; 
}


#endif
