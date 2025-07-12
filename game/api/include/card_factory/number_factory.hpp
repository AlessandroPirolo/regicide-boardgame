#ifndef NUMBER_FACTORY_H
#define NUMBER_FACTORY_H

#include "../card_factory.hpp"

class NumberFactory : public CardFactory {
  public:
    Card* create(unsigned int value, Suit suit) const override;

};

#endif // !NUMBER_FACTORY_H
