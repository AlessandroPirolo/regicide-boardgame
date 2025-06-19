#ifndef PLAYER_H
#define PLAYER_H

#include <list>

using namespace std;

class Card;

namespace Players {
  class Player {
    public:
      Player(list<Card> handcard);
      ~Player();
      Player(const Player &other);

      void play(Card &card);
      void draw(list<Card> &deck);
      list<Card> getCards() const;

    private:
      list<Card> cards;
  }; 
}

#endif
