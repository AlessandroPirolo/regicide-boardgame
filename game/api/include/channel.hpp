#ifndef CHANNEL_H
#define CHANNEL_H

#include <condition_variable>
#include <mutex>
#include <vector>
#include <list>

template <typename T> 
class Channel {
  public:
    void send(std::list<T> args) const;
    std::list<T> recv() const;
    Channel* clone() const;

  private:
    Channel(unsigned int copies = 1);
    std::mutex m;
    std::vector<T> buff;
    bool empty;
    std::condition_variable cv;
    unsigned int copies;
};

#endif // !CHANNEL_H
