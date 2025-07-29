#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <set>

class Card;
enum class Suit : unsigned int;

class Player {
  public:
    Player(std::set<Card> handcard);
    ~Player();
    Player(const Player &other);
    Player();

    bool play(std::list<Card> cards) const;
    bool discard(std::list<Card> cards) const;
    void draw(std::list<Card> &deck) const;
    std::list<Card> dumpPlayingCards() const;
    std::set<Card> getCards() const;
    std::list<Card> getPlayingCards() const;
    void nullifyEffectOf(Suit suit) const;
    void activateEffectOf(Suit suit) const;
    void doubleAtk() const;
    void resetAtk() const;

  private:
    mutable std::set<Card> cards;
    mutable std::list<Card> playing_cards;
}; 

#endif
