#ifndef JOLLY_H
#define JOLLY_H

#include "card.hpp"

namespace Jollies {
  class Jolly: public Cards::Card {
    public:
      Jolly();
      virtual void effect() override;

    private:
  };
}

#endif
