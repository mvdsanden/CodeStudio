#ifndef __INC_MVDS_EVENTHANDLER_HH__
#define __INC_MVDS_EVENTHANDLER_HH__

namespace mvds {


  /** Event handler
   *
   *  This is a base class for event handlers.
   *
   *  It can be registered to an event slot.
   */
  template <typename... Args>
  class EventHandler {
  public:

    // Add your public member functions here...

    /**
     *  Signals the event handler.
     */
    virtual void operator()(Args... args) = 0;

    template <typename Obj>
    static EventHandler<Args...> *create(void (Obj::*fptr)(Args...), Obj *obj);

  private:

    // Add your private members...

  };

  /*
  template <typename Obj, typename... Args>
  class MemberHandler;

  template <typename Obj, typename... Args>
  inline EventHandler<Args...> *EventHandler<Args...>::create(void (Obj::*fptr)(Args...), Obj *obj)
  {
    return new MemberHandler<Obj,Args...>(fptr,obj);
  }
  */
};

//#include "../MemberHandler/memberhandler.hh"

#endif // __INC_MVDS_EVENTHANDLER_HH__

