#include "../../include/game/game_status.hpp"
#include <algorithm>
#include <random>

GameStatus::GameStatus(unsigned int max_cards, unsigned int turn) 
  : turn(turn), max_cards(max_cards), waste_heap(), current_boss(Boss()) 
{}

void GameStatus::addPlayers(std::list<Player> players) {
  this->players = players;
}

void GameStatus::addMainDeck(std::list<Card> main_deck) {
  this->main_deck = main_deck;
}

void GameStatus::addBossDeck(std::list<Boss> boss_deck) {
  this->boss_deck = boss_deck;
}

void GameStatus::nextBoss() {
  current_boss = boss_deck.front();
  boss_deck.pop_front();
}

void GameStatus::nextPlayer() {
  Player& tmp = this->players.front();
  this->players.pop_front();
  this->players.emplace_back(tmp);
}

void GameStatus::nextTurn() {
  this->turn++;
}

void GameStatus::decreaseAtk(unsigned int amount) {
  unsigned int boss_atk = current_boss.getAttack();
  current_boss.setAttack(boss_atk - amount);
}

void GameStatus::doubleAtk(unsigned int amount) {
  unsigned int boss_life = current_boss.getLife();
  current_boss.setLife(boss_life - amount);
}

void GameStatus::nullifyEfct() {
  current_boss.setIsEffect(false);
  Suit boss_suit = current_boss.getSuit();
  for (Player p : players) {
    p.activateEffectOf(boss_suit);
  }
}

void GameStatus::draw(unsigned int amount) { 
  unsigned int i = 0;
  std::list<Player>::iterator it = this->players.begin();

  while (i < amount && it != this->players.end()) {
    if (it->getCards().size() < max_cards) {
      it->draw(this->main_deck);
    }
    it++;
    i++;
  }
}

void GameStatus::shuffle(unsigned int amount) {
  // shuffle randomly waste_heap
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(waste_heap.begin(), waste_heap.end(), g);
  std::list<Card> heal (amount);
  //chosen by the player 
  for (int i = 0; i < amount; i++) { // WILL BE REMOVED
    heal.emplace_back(waste_heap.back());
    waste_heap.pop_back();
  }
}
