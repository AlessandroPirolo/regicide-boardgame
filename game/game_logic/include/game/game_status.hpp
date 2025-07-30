#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <list>
#include <set>

class Player;
class Card;
class Boss;
template <typename T> class Channel;

class GameStatus {
  public:
    bool play(std::list<Card> move) const;
    bool won() const;
    void resolveEffects() const;
    void attack() const;
    bool defend(Channel<Card>& ch) const;

    GameStatus(unsigned int max_cards, unsigned int turn = 0);

    void addPlayers(std::list<Player> players) const;
    void addMainDeck(std::list<Card> main_deck) const;
    void addBossDeck(std::list<Boss> boss_deck) const;
    void nextBoss() const;
    void nextPlayer() const;
    void nextTurn() const;
    Boss getCurrentBoss() const;

  private:
    void draw(unsigned int amount) const;
    void decreaseAtk(unsigned int amount) const;
    void doubleAtk() const;
    void nullifyEfct() const;
    void shuffle(unsigned int amount) const;
    
    mutable std::list<Player> players;
    mutable std::list<Card> main_deck;
    mutable std::list<Card> waste_heap;
    mutable std::list<Boss> boss_deck;
    mutable Boss* current_boss;
    mutable Player* current_player;
    mutable unsigned int turn;
    mutable unsigned int phase;
    unsigned int max_cards;
};

#endif
