#include "../include/channel.hpp"
#include <mutex>

using namespace Channels;

template <typename T>
void Channel<T>::send(std::list<T> args) const {
  if (!args.empty())
  {
    std::unique_lock ul(this->m);
    this->cv.wait(ul, [this]{ return this->empty; });
    for (T elem : args) 
    {
      this->buff.emplace_back(elem);
      this->empty = false;
    }
    ul.unlock();
    this->cv.notify_one();
  }
}

template <typename T>
std::list<T> Channel<T>::recv() const {
  std::unique_lock ul(this->m);
  this->cv.wait(ul, [this]{ return !this->empty; });
  std::list<T> res(this->buff.size());
  for (T elem : this->buff) 
  {
    res.emplace_back(elem);
  }
  this->buff.clear();
  this->empty = true;
  ul.unlock();
  this->cv.notify_one();
  return res;
}
