#ifndef CARD_H
#define CARD_H

enum class Value : unsigned int;
enum class Suit : unsigned int;

namespace Cards {
  class Card {
    public:
      Card(Suit suit, Value value, bool is_effect);
      ~Card();
      Card(const Card &other);
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
