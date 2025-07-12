#include "../../include/player/player.hpp"
#include "../../include/card/card.hpp"
#include "../../include/utilities/utility.hpp"

Player::Player(std::list<Card> cards) 
  : cards(cards), played_cards(), playing_cards()
{

}

Player::Player()
  : cards(), playing_cards(), played_cards()
{}

Player::~Player() {}

Player::Player(const Player &other) 
  : cards(other.cards)
{

}

std::list<Card> Player::getCards() {
  return cards;
}

std::list<Card> Player::getPlayedCards() {
  return played_cards;
}

std::list<Card> Player::getPlayingCards() {
  return playing_cards;
}

void Player::nullifyEffectOf(Suit suit) {
  for(Card c : cards) {
    if(c.getSuit() == suit) c.setIsEffect(false);
  }
}

void Player::activateEffectOf(Suit suit) {
  for(Card c : cards) {
    if(c.getSuit() == suit) c.setIsEffect(true);
  }
}

void Player::play(std::list<Card> cards) {}

void Player::draw(std::list<Card> &deck) {
  Card& card = deck.back();
  cards.push_back(card);
  deck.pop_back(); 
}

