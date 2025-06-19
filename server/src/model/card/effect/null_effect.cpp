#include "../../../../include/model/card/effect/null_effect.hpp"

void NullEffect::NullEffect::perform(Status::IGameStatus* status) {
  status->nullifyEfct();
} 
