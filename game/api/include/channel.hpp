#ifndef CHANNEL_H
#define CHANNEL_H

#include <condition_variable>
#include <mutex>
#include <vector>
#include <list>

namespace Channels {
  template <typename T> 
  class Channel {
    public:
      void send(std::list<T> args) const;
      std::list<T> recv() const;
      Channel* clone() const;

    private:
      Channel(unsigned int copies = 1);
      mutable std::mutex m;
      mutable std::vector<T> buff;
      mutable bool empty;
      mutable std::condition_variable cv;
      mutable unsigned int copies;
  };
}

#endif // !CHANNEL_H
