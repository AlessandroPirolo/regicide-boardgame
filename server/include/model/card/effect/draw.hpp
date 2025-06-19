#ifndef DRAWEFFECT_H
#define DRAWEFFECT_H

#include "ieffect.hpp"

using namespace Effect;

namespace Draw {
  class Draw: public IEffect {
    public:
      virtual void perform(Status::IGameStatus* status) override;
  };
}

#endif
