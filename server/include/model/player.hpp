#ifndef PLAYER_H
#define PLAYER_H
#include "card.hpp"
#include <list>

using namespace std;

namespace Player {
  class Player {
    public:
      Player(list<Card::Card> handcard);
      ~Player();
      Player(const Player &other);

      void play(Card::Card &card);
      void draw(list<Card::Card> &deck);
      list<Card::Card> getCards() const;

    private:
      list<Card::Card> cards;
  }; 
}

#endif
