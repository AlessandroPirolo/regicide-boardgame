#include "../../include/model/player.hpp"
#include "../../include/model/card.hpp"

using namespace std;

Players::Player::Player(list<Cards::Card> cards) 
  : cards(cards)
{

}

Players::Player::~Player() {}

Players::Player::Player(const Player &other) 
  : cards(other.cards)
{

}

list<Cards::Card> Players::Player::getCards() const {
  return cards;
}

void Players::Player::play(Cards::Card &card) {}

void Players::Player::draw(list<Cards::Card> &deck) {
  Cards::Card& card = deck.back();
  cards.push_back(card);
  deck.pop_back(); 
}

