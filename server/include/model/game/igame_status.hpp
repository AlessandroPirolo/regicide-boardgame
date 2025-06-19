#ifndef IGAMESTATUS_H
#define IGAMESTATUS_H

namespace Status {
  class IGameStatus {
    public:
      virtual void draw() = 0;
      virtual void shuffle() = 0;
      virtual void decreaseAtk() = 0;
      virtual void doubleAtk() = 0;
      virtual void nullifyEfct() = 0;

  };
}

#endif // !IGAMESTATUS_H

