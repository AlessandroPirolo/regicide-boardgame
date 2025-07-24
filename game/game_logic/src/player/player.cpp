#include "../../include/player/player.hpp"
#include "../../include/card/card.hpp"
#include "../../include/utilities/utility.hpp"

Player::Player(std::set<Card> cards) 
  : cards(cards), played_cards(), playing_cards()
{}

Player::Player()
  : cards(), playing_cards(), played_cards()
{}

Player::~Player() {}

Player::Player(const Player &other) 
  : cards(other.cards)
{}

std::set<Card> Player::getCards() const {
  return cards;
}

std::list<Card> Player::getPlayedCards() const {
  return played_cards;
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

void Player::play(std::list<Card> cards) const {
  for (const Card& c : cards) 
  {
    std::set<Card>::iterator it = this->cards.find(c);
    this->playing_cards.emplace_back(it);
  }
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

