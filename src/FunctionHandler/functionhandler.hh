#ifndef __INC_MVDS_FUNCTIONHANDLER_HH__
#define __INC_MVDS_FUNCTIONHANDLER_HH__

#include "../EventHandler/eventhandler.hh"

namespace mvds {


  /** Member function event handler.
   *
   *  This event handler calls a member function.
   */
  template <typename... Args>
  class FunctionHandler : public EventHandler<Args...> {
  public:

    /**
     *  Creates a member function handler.
     */
    FunctionHandler(void (*fptr)(Args...));

    // Add your public member functions here...

    /**
     *  Signals the event handler.
     */
    virtual void operator()(Args... args);

  private:

    // Add your private members...

    void (*d_fptr)(Args...);

  };

  template <typename... Args>
  inline FunctionHandler<Args...>::FunctionHandler(void (*fptr)(Args...))
    : d_fptr(fptr)
  {
  }

  template <typename... Args>
  inline void FunctionHandler<Args...>::operator()(Args... args)
  {
    (*d_fptr)(args...);
  }

  template <typename... Args>
  inline EventHandler<Args...> *call(void (*fptr)(Args...))
  {
    return new FunctionHandler<Args...>(fptr);
  }

};


#endif // __INC_MVDS_FUNCTIONHANDLER_HH__
