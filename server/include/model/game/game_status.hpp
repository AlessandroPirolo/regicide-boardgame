#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include "igame_status.hpp"
#include "../card/boss.hpp"
#include "../player/player.hpp"
#include <list>

using namespace Players;
using namespace Bosses;

namespace Status {
  class GameStatus: public IGameStatus {
    public:
      virtual void draw(unsigned int amount) override;
      virtual void decreaseAtk(unsigned int amount) override;
      virtual void doubleAtk(unsigned int amount) override;
      virtual void nullifyEfct() override;
      virtual void shuffle(unsigned int amount) override;
      GameStatus(unsigned int max_cards, unsigned int turn = 0);

      void addPlayers(std::list<Player> players);
      void addMainDeck(std::list<Card> main_deck);
      void addBossDeck(std::list<Boss> boss_deck);
      void nextBoss();
      void nextPlayer();
      void nextTurn();

    private:
      std::list<Player> players;
      std::list<Card> main_deck;
      std::list<Card> waste_heap;
      std::list<Boss> boss_deck;
      Boss current_boss;
      unsigned int turn;
      unsigned int max_cards;
  };
}

#endif
