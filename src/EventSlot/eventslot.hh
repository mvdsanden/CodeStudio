#ifndef __INC_MVDS_EVENTSLOT_HH__
#define __INC_MVDS_EVENTSLOT_HH__

#include <list>

#include "../EventHandler/eventhandler.hh"

namespace mvds {


  /** Event slot
   *
   *  You can connect event handelers to this.
   *
   */
  template <typename... Args>
  class EventSlot {

    EventSlot(EventSlot const &other); // NI
    EventSlot &operator=(EventSlot const &other); // NI

  public:

    EventSlot();

    ~EventSlot();

    // Add your public member functions here...

    /**
     *  Connect an handler to this event slot.
     */
    void connect(EventHandler<Args...> *handler);

    /**
     *  Signal the event slot.
     */
    void signal(Args... args);

  private:

    // Add your private members...

    std::list<EventHandler<Args...>*> d_handlers;

  };

  template <typename... Args>
  EventSlot<Args...>::EventSlot()
  {

    // Put your construction code here...

  }


  template <typename... Args>
  inline EventSlot<Args...>::~EventSlot()
  {
    // Delete all handlers.
    for (auto i = d_handlers.begin(); i != d_handlers.end(); ++i)
      delete *i;
  }

  template <typename... Args>
  inline void EventSlot<Args...>::connect(EventHandler<Args...> *handler)
  {
    d_handlers.push_back(handler);
  }

  template <typename... Args>
  inline void EventSlot<Args...>::signal(Args... args)
  {
    // Delete all handlers.
    for (auto i = d_handlers.begin(); i != d_handlers.end(); ++i)
      (**i)(args...);
  }

};


#endif // __INC_MVDS_EVENTSLOT_HH__

