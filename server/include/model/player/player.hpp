#ifndef PLAYER_H
#define PLAYER_H

#include "../../../include/model/card/boss.hpp"
#include "list"
using namespace std;

namespace Players {
  class Player {
    public:
      Player(list<Card> handcard);
      ~Player();
      Player(const Player &other);
      Player();

      void play(list<Card> cards);
      void draw(list<Card> &deck);
      list<Card> getCards();
      list<Card> getPlayedCards();
      list<Card> getPlayingCards();
      void nullifyEffectOf(Suit suit);
      void activateEffectOf(Suit suit);

    private:
      list<Card> cards;
      list<Card> playing_cards;
      list<Card> played_cards;
  }; 
}

#endif
