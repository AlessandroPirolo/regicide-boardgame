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

    void play(std::list<Card> cards) const;
    void draw(std::list<Card> &deck) const;
    std::list<Card> dumpPlayingCards() const;
    std::set<Card> getCards() const;
    std::list<Card> getPlayedCards() const;
    std::list<Card> getPlayingCards() const;
    void nullifyEffectOf(Suit suit) const;
    void activateEffectOf(Suit suit) const;
    void doubleAtk() const;

  private:
    mutable std::set<Card> cards;
    mutable std::list<Card> playing_cards;
    mutable std::list<Card> played_cards;
}; 

#endif
