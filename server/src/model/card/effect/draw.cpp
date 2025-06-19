#include "../../../../include/model/card/effect/draw.hpp"

void Draw::Draw::perform(Status::IGameStatus* status) {
  status->draw();
} 
