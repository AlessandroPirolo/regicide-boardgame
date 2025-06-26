#include "../../../include/model/player/player.hpp"
#include "../../../include/model/card/card.hpp"
#include "../../../include/model/utilities/utility.hpp"

using namespace std;
using namespace Utility;
using namespace Players;
using namespace Cards;

Player::Player(list<Card> cards) 
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

list<Card> Player::getCards() {
  return cards;
}

list<Card> Player::getPlayedCards() {
  return played_cards;
}

list<Card> Player::getPlayingCards() {
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

void Player::play(Card &card) {}

void Player::draw(list<Card> &deck) {
  Card& card = deck.back();
  cards.push_back(card);
  deck.pop_back(); 
}

