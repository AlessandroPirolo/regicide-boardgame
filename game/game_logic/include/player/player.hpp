#ifndef PLAYER_H
#define PLAYER_H

#include "../../../include/model/card/card.hpp"
#include <list>
using namespace Cards;

namespace Players {
  class Player {
    public:
      Player(std::list<Card> handcard);
      ~Player();
      Player(const Player &other);
      Player();

      void play(std::list<Card> cards);
      void draw(std::list<Card> &deck);
      std::list<Card> getCards();
      std::list<Card> getPlayedCards();
      std::list<Card> getPlayingCards();
      void nullifyEffectOf(Suit suit);
      void activateEffectOf(Suit suit);

    private:
      std::list<Card> cards;
      std::list<Card> playing_cards;
      std::list<Card> played_cards;
  }; 
}

#endif
