#ifndef BOSS_FACTORY_H
#define BOSS_FACTORY_H

#include "../card_factory.hpp"

class BossFactory : public CardFactory {
  public:
    Card* create(unsigned int value, Suit suit) const override;

};

#endif // !BOSS_FACTORY_H
