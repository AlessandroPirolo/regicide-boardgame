#ifndef EFFECT_H
#define EFFECT_H

#include "../../game/igame_status.hpp"

namespace Effect {
  class IEffect {
    public:
      virtual void perform(Status::IGameStatus* status, unsigned int amount) = 0;
  };
}

#endif
