#ifndef GAME_H
#define GAME_H

class GameStatus;
template <typename T> class Channel;
class Card;

class Game {
  public:
    Game(GameStatus *status);
    ~Game();
    void play();

  private:
    void step1();
    void step2();
    void step3();
    void step4();
    bool won();

    GameStatus *status;
    Channel<Card> *ch;
};
#endif
