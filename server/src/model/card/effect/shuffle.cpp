#include "../../../../include/model/card/effect/shuffle.hpp"

void Shuffle::Shuffle::perform(Status::IGameStatus* status) {
  status->shuffle();
} 
