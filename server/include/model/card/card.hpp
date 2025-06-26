#ifndef CARD_H
#define CARD_H

#include "effect/ieffect.hpp"
#include "../utilities/utility.hpp"

using namespace Utility;

namespace Cards {
  class Card {
    public:
      Card(Suit suit, Value value, bool is_effect, Effect::IEffect* effect);
      ~Card();
      Card(const Card &other);
      Card();
      Suit getSuit() const;
      void setSuit(Suit suit);

      Value getValue() const;
      void setValue(Value value);

      bool getIsEffect() const;
      void setIsEffect(bool val); 

    private:
      Suit suit;
      Value value;
      bool is_effect;
      Effect::IEffect* effect;
      

  };  
}

#endif
