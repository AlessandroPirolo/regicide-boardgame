#ifndef NUMBER_H
#define NUMBER_H
#include "card.hpp"

class Number: public Card {
  public:
    Number(Suit suit, Value value, bool is_effect, Effect *effect);
    ~Number();
    Number(const Number &other);
}; 


#endif
