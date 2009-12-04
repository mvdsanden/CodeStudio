#ifndef __INC_MVDS_DEFEREDCALL_HH__
#define __INC_MVDS_DEFEREDCALL_HH__

#include "../EventHandler/eventhandler.hh"
#include "../MemberHandler/memberhandler.hh"
#include "../FunctionHandler/functionhandler.hh"

#include <tuple>

namespace mvds {


  /**
   *
   *
   */
  template <typename... Args>
  class DeferedCall : public EventHandler<> {
  public:

    DeferedCall(EventHandler<Args...> *handler, Args... args)
      : d_handler(handler),
	d_args(args...)
    {
    }

    virtual void operator()();
    //    {
    //      (*d_handler)(d_args);
    //    }

  private:

    // Add your private members...

    EventHandler<Args...> *d_handler;
    std::tuple<Args...>    d_args;

  };

  template <typename... Args>
  inline void DeferedCall<Args...>::operator()()
  {
    (*d_handler)(d_args);
  }


  template <typename... Args, typename Obj>
  inline EventHandler<> *call(void (Obj::*fptr)(Args...), Obj &obj, Args... args)
  {
    return new DeferedCall<Args...>(new MemberHandler<Obj,Args...>(fptr,obj),args...);
  }

  template <typename... Args>
  inline EventHandler<> *call(void (*fptr)(Args...), Args... args)
  {
    return new DeferedCall<Args...>(new FunctionHandler<Args...>(fptr),args...);
  }

};


#endif // __INC_MVDS_DEFEREDCALL_HH__

