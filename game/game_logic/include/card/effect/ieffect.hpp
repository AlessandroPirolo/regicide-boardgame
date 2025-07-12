#ifndef EFFECT_H
#define EFFECT_H

enum class TypeEffect : unsigned int {
  Shuffle = 0,
  Draw = 1,
  DecreaseAtk = 2,
  DoubleAtk = 3,
  NullEffect = 4
};

struct Effect {
  TypeEffect type;
  unsigned int value;
};


#endif
