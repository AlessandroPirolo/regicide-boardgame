#ifndef JOLLY_H
#define JOLLY_H

#include "card.hpp"

class IEffect;

namespace Jollies {
  class Jolly: public Cards::Card {
    public:
      Jolly(IEffect* effect);

    private:
  };
}

#endif
