#ifndef __INC_MVDS_EVENTHANDLER_HH__
#define __INC_MVDS_EVENTHANDLER_HH__

#include <tuple>
#include <stdexcept>

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

    void operator()(std::tuple<Args...> &t);

    template <typename Obj>
    static EventHandler<Args...> *create(void (Obj::*fptr)(Args...), Obj *obj);

  private:

    // Add your private members...

  };

  template <typename T0>
  inline void tupleCall(EventHandler<T0> *handler,
			std::tuple<T0> &t)
  {
    (*handler)(std::get<0>(t));
  }

  template <typename T0, typename T1>
  inline void tupleCall(EventHandler<T0,T1> *handler,
			std::tuple<T0,T1> &t)
  {
    (*handler)(std::get<0>(t),
	       std::get<1>(t));
  }

  template <typename T0, typename T1, typename T2>
  inline void tupleCall(EventHandler<T0,T1,T2> *handler,
			std::tuple<T0,T1,T2> &t)
  {
    (*handler)(std::get<0>(t),
	       std::get<1>(t),
	       std::get<2>(t));
  }

  template <typename T0, typename T1, typename T2, typename... Args>
  inline void tupleCall(EventHandler<T0,T1,T2,Args...> *handler,
			std::tuple<T0,T1,T2,Args...> &t)
  {
    throw std::runtime_error("tuple calls with more than 3 arguments not yet implemented");
  }


  template <typename... Args>
  inline void EventHandler<Args...>::operator()(std::tuple<Args...> &t)
  {
    //    (*this)(get<0>(t));
    tupleCall<Args...>(this,t);
  }

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

