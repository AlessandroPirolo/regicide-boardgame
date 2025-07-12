#ifndef JOLLY_FACTORY_H
#define JOLLY_FACTORY_H

#include "../card_factory.hpp"

class JollyFactory : public CardFactory {
  public:
    Card* create(unsigned int value, Suit suit) const override;
};

#endif // !JOLLY_FACTORY_H
