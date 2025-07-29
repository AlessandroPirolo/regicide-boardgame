#ifndef UTILITY_H
#define UTILITY_H

#include <list>
#include <algorithm>
#include <map>
#include <random>

enum class Suit : unsigned int {
  None = 0,
  Hearts = 1,
  Diamonds = 2,
  Clubs = 3,
  Spades = 4
};

enum class Value : unsigned int {
  None = 0,
  Ace = 1,
  Two = 2,
  Three = 3,
  Four = 4,
  Five = 5,
  Six = 6,
  Seven = 7,
  Eight = 8,
  Nine = 9,
  Ten = 10,
  Jack = 10,
  Queen = 15,
  King = 20
};

namespace UtilityMethod {
  template <typename T> 
  void shuffle(std::list<T>& l) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(l.begin(), l.end(), g);
  }
}
#endif
