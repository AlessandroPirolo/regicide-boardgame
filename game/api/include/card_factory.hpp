#ifndef CARDAPI_H
#define CARDAPI_H 

class Card;
enum class Suit : unsigned int;

class CardFactory {
  public:
    virtual Card* create(unsigned int value, Suit suit) const = 0;
};

#endif 
