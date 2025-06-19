#ifndef GAME_H
#define GAME_H

struct GameStatus;

namespace Games {
  class Game {
    public:
      Game(GameStatus *status);
      ~Game();
      void play();

    private:
      GameStatus *status;
  };
  
}

#endif
