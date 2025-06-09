#include "../../include/model/player.hpp"
#include "../../include/model/card.hpp"

using namespace std;

Player::Player::Player(list<Card::Card> cards) 
  : cards(cards)
{

}

Player::Player::~Player() {}

Player::Player::Player(const Player &other) 
  : cards(other.cards)
{

}

list<Card::Card> Player::Player::getCards() const {
  return cards;
}

void Player::Player::play(Card::Card &card) {}

void Player::Player::draw(list<Card::Card> &deck) {
  Card::Card& card = deck.back();
  cards.push_back(card);
  deck.pop_back(); 
}

