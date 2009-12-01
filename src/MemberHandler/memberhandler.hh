#ifndef __INC_MVDS_MEMBERHANDLER_HH__
#define __INC_MVDS_MEMBERHANDLER_HH__

#include "../EventHandler/eventhandler.hh"

namespace mvds {


  /** Member function event handler.
   *
   *  This event handler calls a member function.
   */
  template <typename Obj, typename... Args>
  class MemberHandler : public EventHandler<Args...> {
  public:

    /**
     *  Creates a member function handler.
     */
    MemberHandler(void (Obj::*fptr)(Args...), Obj &obj);

    // Add your public member functions here...

    /**
     *  Signals the event handler.
     */
    virtual void operator()(Args... args);

  private:

    // Add your private members...

    void (Obj::*d_fptr)(Args...);
    Obj &d_obj;

  };

  template <typename Obj, typename... Args>
  inline MemberHandler<Obj,Args...>::MemberHandler(void (Obj::*fptr)(Args...), Obj &obj)
    : d_fptr(fptr),
      d_obj(obj)
  {
  }

  template <typename Obj, typename... Args>
  inline void MemberHandler<Obj,Args...>::operator()(Args... args)
  {
    (d_obj.*d_fptr)(args...);
  }

  template <typename... Args, typename Obj>
  inline EventHandler<Args...> *call(void (Obj::*fptr)(Args...), Obj &obj)
  {
    return new MemberHandler<Obj,Args...>(fptr,obj);
  }

};


#endif // __INC_MVDS_MEMBERHANDLER_HH__

