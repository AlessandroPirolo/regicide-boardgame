#ifndef PLAYER_H
#define PLAYER_H
#include "card.hpp"
#include <list>

namespace Player {
  class Player {
    public:
      Player(Card::Card handcard);
      ~Player();
      Player(const Card::Card &player);

      void play(Card::Card card);
      std::list<Card::Card> getCards() const;

    private:
      std::list<Card::Card> cards;
  }; 
}

#endif
