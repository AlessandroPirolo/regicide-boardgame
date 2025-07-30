#include "../../include/game/game_status.hpp"
#include "../../include/card/boss.hpp"
#include "../../include/player/player.hpp"
#include "../../../api/include/channel.hpp"
#include "../../include/utilities/utility.hpp"

GameStatus::GameStatus(unsigned int max_cards, unsigned int turn) 
  : turn(turn), max_cards(max_cards), waste_heap(), current_boss(new Boss()), current_player(new Player()) 
{}

void GameStatus::addPlayers(std::list<Player> players) const {
  this->players = players;
  current_player = &players.front();
}

void GameStatus::addMainDeck(std::list<Card> main_deck) const {
  UtilityMethod::shuffle(main_deck);
  this->main_deck = main_deck;
}

void GameStatus::addBossDeck(std::list<Boss> boss_deck) const {
  this->boss_deck = boss_deck;
  nextBoss();
}

void GameStatus::nextBoss() const {
  if (boss_deck.size() > 0)
  {
    current_boss = &boss_deck.front();
    boss_deck.pop_front();
    
    for (const Player& p : players)
    {
      p.nullifyEffectOf(current_boss->getSuit());
    }
  }
}

void GameStatus::nextPlayer() const {
  Player& tmp = players.front();
  players.pop_front();
  players.emplace_back(tmp);
  current_player = &players.front();
}

void GameStatus::nextTurn() const {
  turn++;
}

bool GameStatus::play(std::list<Card> move) const {
  return current_player->play(move);
}

void GameStatus::resolveEffects() const {
  std::list<Card> playingCards = current_player->getPlayingCards();
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
    shuffle(amount);
  }

  for (const Effect effect : effects) 
  {
    switch (effect) 
    {
      case Effect::DecreaseAtk:
        decreaseAtk(amount);
      case Effect::DoubleAtk:
        doubleAtk();
      case Effect::Draw:
        draw(amount);
      case Effect::NullEffect:
        nullifyEfct();
    }
  }
}

void GameStatus::attack() const {
  unsigned int attack_power = 0;
  for (const Card& c : current_player->getPlayingCards())
  {
    attack_power += c.getAtk();
  }
  current_boss->decreaseLife(attack_power);

  current_player->resetAtk();
}

Boss GameStatus::getCurrentBoss() const {
  return *current_boss;
}

bool find_combo(std::set<Card> s, Card card, unsigned int atk) {
  bool found = false;
  unsigned int card_value = int(card.getValue());
  for (Card c : s) found = found && ((card_value + int(c.getValue())) >= atk);

  return found;
}

bool defendable(std::set<Card> s, unsigned int atk) {
  bool found = false;
  for (Card c : s) 
  {
    auto nh = s.extract(c);
    found = found && find_combo(s, nh.value(), atk);
    s.insert(std::move(nh));
  }

  return found;
}
 
bool GameStatus::defend(Channel<Card>& ch) const {
  std::set<Card> player_cards = current_player->getCards();
  unsigned int boss_atk = current_boss->getAtk();
  if (defendable(player_cards, boss_atk))
  {
    std::list<Card> defending_cards = ch.recv();
    if (!current_player->discard(defending_cards)) return false;

    for (const Card& c : defending_cards) 
    {
      waste_heap.emplace_front(c);
    }
    return true;
  }
  else 
  {
    return false;
  }
}

bool GameStatus::won() const {
  return boss_deck.empty();
}

/* private methods */
void GameStatus::decreaseAtk(unsigned int amount) const {
  unsigned int boss_atk = current_boss->getAtk();
  current_boss->setAtk(boss_atk - amount);
}

void GameStatus::doubleAtk() const {
  current_player->doubleAtk();
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
  std::list<Player>::iterator it = players.begin();

  while (i < amount && reached_max) 
  {
    for (const Player& p : players) 
    {
      reached_max = reached_max || (p.getCards().size() < max_cards);
    }

    if (it == players.end()) it = players.begin();

    if (it->getCards().size() < max_cards)
    {
      it->draw(main_deck);
      i++;
    }
    it++;
  }
}

void GameStatus::shuffle(unsigned int amount) const {
  // shuffle randomly waste_heap
  UtilityMethod::shuffle(waste_heap);
  std::list<Card> heal (amount);
  //chosen by the player 
  for (int i = 0; i < amount; i++) 
  { // WILL BE REMOVED
    heal.emplace_back(waste_heap.back());
    waste_heap.pop_back();
  }
}

