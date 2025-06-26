#ifndef IGAMESTATUS_H
#define IGAMESTATUS_H

namespace Status {
  class IGameStatus {
    public:
      virtual void draw(unsigned int amount) = 0;
      virtual void shuffle(unsigned int amount) = 0;
      virtual void decreaseAtk(unsigned int amount) = 0;
      virtual void doubleAtk(unsigned int amount) = 0;
      virtual void nullifyEfct() = 0;

  };
}

#endif // !IGAMESTATUS_H

