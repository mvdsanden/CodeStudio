#ifndef __INC_MVDS_GTKDISTRIBUTOR_HH__
#define __INC_MVDS_GTKDISTRIBUTOR_HH__

#include "../EventDistributor/eventdistributor.hh"
#include "../Socket/socket.hh"
#include "../MutexLock/mutexlock.hh"

#include <gtkmm.h>
#include <queue>

namespace mvds {


  /**
   *
   *
   */
  class GTKDistributor : public EventDistributor {

    void destroy();

  public:

    GTKDistributor();

    virtual ~GTKDistributor() { destroy(); }

    virtual void distribute(EventHandler<> *event);

    void signal();

    bool onSignal(Glib::IOCondition condition);

  private:

    // Add your private members...

    Socket::Pair d_socketPair;
    sigc::connection d_sigCon;
    std::queue<EventHandler<>*> d_queue;
    MutexLock d_mutex;

  };

  inline void GTKDistributor::distribute(EventHandler<> *event)
  {
    // Queue the event.
    d_mutex.lock();
    {
      d_queue.push(event);
    }
    d_mutex.unlock();

    // Signal the GTK thread.
    signal();
  }

};


#endif // __INC_MVDS_GTKDISTRIBUTOR_HH__

