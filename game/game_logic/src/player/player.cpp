#include "../../include/player/player.hpp"
#include "../../include/card/card.hpp"
#include "../../include/utilities/utility.hpp"

Player::Player(std::set<Card> cards) 
  : cards(cards), playing_cards()
{}

Player::Player()
  : cards(), playing_cards()
{}

Player::~Player() {}

Player::Player(const Player &other) 
  : cards(other.cards)
{}

std::set<Card> Player::getCards() const {
  return cards;
}

std::list<Card> Player::getPlayingCards() const {
  return playing_cards;
}

void Player::nullifyEffectOf(Suit suit) const {
  for (const Card& c : cards) 
  {
    if(c.getSuit() == suit) c.setIsEffect(false);
  }
}

void Player::activateEffectOf(Suit suit) const {
  for (const Card& c : cards) 
  {
    if(c.getSuit() == suit) c.setIsEffect(true);
  }
}

bool Player::play(std::list<Card> cards) const {
  for (const Card& c : cards) 
  {
    std::set<Card>::iterator it = this->cards.find(c);
    if (it == this->cards.end()) return false;

    this->playing_cards.emplace_back(it);
  }
  return true;
}

bool Player::discard(std::list<Card> cards) const {
  for (const Card& c : cards) 
  {
    unsigned int num = this->cards.erase(c);
    if (num == 0) return false;
  }
  return true;
}

void Player::draw(std::list<Card> &deck) const {
  Card& card = deck.back();
  cards.emplace(card);
  deck.pop_back(); 
}

void Player::doubleAtk() const {
  for (const Card& c : playing_cards) 
  {
    c.setAtk(c.getAtk() * 2);
  }
}

void Player::resetAtk() const {
  for (const Card& c : playing_cards) 
  {
    c.resetAtk();
  }
}

std::list<Card> Player::dumpPlayingCards() const {
  std::list<Card> dump = this->playing_cards;
  playing_cards.clear();
  return dump;
}
