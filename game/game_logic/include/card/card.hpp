#ifndef CARD_H
#define CARD_H

#include "effect/ieffect.hpp"
#include "../utilities/utility.hpp"


class Card {
  public:
    Card(Suit suit, Value value, bool is_effect, Effect* effect);
    ~Card();
    Card(const Card &other);
    Card();
    bool operator==(const Card &other);

    Suit getSuit() const;
    void setSuit(Suit suit) const;
    Effect getEffect() const; 

    Value getValue() const;
    void setValue(Value value) const;

    unsigned int getAtk() const;
    void setAtk(unsigned int atk) const;

    bool getIsEffect() const;
    void setIsEffect(bool val) const; 

    void resetAtk() const;

  private:
    mutable Suit suit;
    mutable Value value;
    mutable bool is_effect;
    Effect* effect;
    mutable unsigned int attack;
};  

#endif
