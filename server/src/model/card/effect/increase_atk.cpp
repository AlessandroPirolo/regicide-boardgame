#include "../../../../include/model/card/effect/increase_atk.hpp"

void IncreaseAtk::IncreaseAtk::perform(Status::IGameStatus* status) {
  status->doubleAtk();
} 
