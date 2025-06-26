#ifndef DRAWEFFECT_H
#define DRAWEFFECT_H

#include "ieffect.hpp"

using namespace Effect;

namespace IncreaseAtk {
  class IncreaseAtk: public IEffect {
    public:
      virtual void perform(Status::IGameStatus* status, unsigned int amount) override;
  };
}

#endif
