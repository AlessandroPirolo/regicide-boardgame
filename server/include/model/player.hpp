#ifndef PLAYER_H
#define PLAYER_H
#include "card.hpp"
#include <list>

using namespace std;

namespace Players {
  class Player {
    public:
      Player(list<Cards::Card> handcard);
      ~Player();
      Player(const Player &other);

      void play(Cards::Card &card);
      void draw(list<Cards::Card> &deck);
      list<Cards::Card> getCards() const;

    private:
      list<Cards::Card> cards;
  }; 
}

#endif
