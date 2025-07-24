#include "../../include/game/game_status.hpp"
#include "../../include/card/boss.hpp"
#include "../../include/player/player.hpp"
#include "../../../api/include/channel.hpp"
#include <algorithm>
#include <random>


GameStatus::GameStatus(unsigned int max_cards, unsigned int turn) 
  : turn(turn), max_cards(max_cards), waste_heap(), current_boss(new Boss()) 
{}

void GameStatus::addPlayers(std::list<Player> players) const {
  this->players = players;
}

void GameStatus::addMainDeck(std::list<Card> main_deck) const {
  this->main_deck = main_deck;
}

void GameStatus::addBossDeck(std::list<Boss> boss_deck) const {
  this->boss_deck = boss_deck;
}

void GameStatus::nextBoss() const {
  if (boss_deck.size() > 0)
  {
    current_boss = &boss_deck.front();
    boss_deck.pop_front();
  }
}

void GameStatus::nextPlayer() const {
  Player& tmp = this->players.front();
  this->players.pop_front();
  this->players.emplace_back(tmp);
}

void GameStatus::nextTurn() const {
  this->turn++;
}

void GameStatus::resolveEffects() const {
  std::list<Card> playingCards = this->players.front().getPlayingCards();
  unsigned int amount = 0;
  std::set<Effect> effects;

  for (const Card &card : playingCards) 
  {
    amount += u_int(card.getValue());
    effects.insert(card.getEffect());
  }

  if (effects.find(Effect::Shuffle) == effects.end()) 
  {
    effects.erase(Effect::Shuffle);
    this->shuffle(amount);
  }

  for (const Effect effect : effects) 
  {
    switch (effect) 
    {
      case Effect::DecreaseAtk:
        this->decreaseAtk(amount);
      case Effect::DoubleAtk:
        this->doubleAtk();
      case Effect::Draw:
        this->draw(amount);
      case Effect::NullEffect:
        this->nullifyEfct();
    }
  }
}

void GameStatus::attack() const {
  unsigned int attack_power = 0;
  for (const Card& c : this->players.front().getPlayingCards())
  {
    attack_power += c.getAtk();
  }
  this->current_boss->decreaseLife(attack_power);
}

void GameStatus::defend(Channel<Card>& ch) const {
  std::list<Card> defending_cards = ch.recv();

}

void GameStatus::decreaseAtk(unsigned int amount) const {
  unsigned int boss_atk = current_boss->getAtk();
  current_boss->setAtk(boss_atk - amount);
}

void GameStatus::doubleAtk() const {
  this->players.front().doubleAtk();
}

void GameStatus::nullifyEfct() const {
  current_boss->setIsEffect(false);
  Suit boss_suit = current_boss->getSuit();
  for (Player p : players) 
  {
    p.activateEffectOf(boss_suit);
  }
}

void GameStatus::draw(unsigned int amount) const {
  unsigned int i = 0;
  bool reached_max = true;
  std::list<Player>::iterator it = this->players.begin();

  while (i < amount && reached_max) 
  {
    for (const Player& p : this->players) 
    {
      reached_max = reached_max || (p.getCards().size() < max_cards);
    }

    if (it == this->players.end()) it = this->players.begin();

    if (it->getCards().size() < max_cards)
    {
      it->draw(this->main_deck);
      i++;
    }
    it++;
  }
}

void GameStatus::shuffle(unsigned int amount) const {
  // shuffle randomly waste_heap
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(waste_heap.begin(), waste_heap.end(), g);
  std::list<Card> heal (amount);
  //chosen by the player 
  for (int i = 0; i < amount; i++) 
  { // WILL BE REMOVED
    heal.emplace_back(waste_heap.back());
    waste_heap.pop_back();
  }
}

bool GameStatus::won() const {
  return this->boss_deck.empty();
}
