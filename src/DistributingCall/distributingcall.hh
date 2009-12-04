#ifndef __INC_MVDS_DISTRIBUTINGCALL_HH__
#define __INC_MVDS_DISTRIBUTINGCALL_HH__

#include "../DeferedCall/deferedcall.hh"
#include "../EventDistributor/eventdistributor.hh"

namespace mvds {


  /**
   *
   *
   */
  template <typename... Args>
  class DistributingCall : public EventHandler<Args...> {
  public:

    DistributingCall(EventDistributor &distributor, EventHandler<Args...> *handler)
      : d_distributor(distributor),
	d_handler(handler)
    {}

    // Add your public member functions here...

    virtual void operator()(Args... args)
    {
      d_distributor.distribute(new DeferedCall<Args...>(d_handler,args...));
    }

  private:

    // Add your private members...

    EventDistributor &d_distributor;
    EventHandler<Args...> *d_handler;

  };

  template <typename... Args, typename Obj>
  inline EventHandler<Args...> *call(EventDistributor &distributor, void (Obj::*fptr)(Args...), Obj &obj)
  {
    return new DistributingCall<Args...>(distributor,new MemberHandler<Obj,Args...>(fptr,obj));
  }

  template <typename... Args>
  inline EventHandler<Args...> *call(EventDistributor &distributor, void (*fptr)(Args...))
  {
    return new DistributingCall<Args...>(distributor,new FunctionHandler<Args...>(fptr));
  }


};


#endif // __INC_MVDS_DISTRIBUTINGCALL_HH__

