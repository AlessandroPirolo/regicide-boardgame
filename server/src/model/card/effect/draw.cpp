#include "../../../../include/model/card/effect/draw.hpp"

void Draw::Draw::perform(Status::IGameStatus* status, unsigned int amount) {
  status->draw(amount);
} 
