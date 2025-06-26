#include "../../../../include/model/card/effect/decrease_atk.hpp"

void DecreaseAtk::DecreaseAtk::perform(Status::IGameStatus* status, unsigned int amount) {
  status->decreaseAtk(amount);
} 
