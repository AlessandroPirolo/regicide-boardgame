#ifndef CARD_H
#define CARD_H
#include "utility.hpp"

using namespace Utility;

namespace Card {
  class Card {
    public:
      Card(Suit suit, Value value, bool is_effect);
      ~Card();
      Card(const Card &other);
      virtual void effect() = 0;
      Suit getSuit() const;

      Value getValue() const;

      bool getIsEffect() const;

    private:
      Suit suit;
      Value value;
      bool is_effect;

  };  
}

#endif
