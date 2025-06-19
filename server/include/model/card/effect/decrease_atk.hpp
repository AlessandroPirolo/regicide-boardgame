#ifndef DRAWEFFECT_H
#define DRAWEFFECT_H

#include "ieffect.hpp"

using namespace Effect;

namespace DecreaseAtk {
  class DecreaseAtk: public IEffect {
    public:
      virtual void perform(Status::IGameStatus* status) override;
  };
}

#endif
