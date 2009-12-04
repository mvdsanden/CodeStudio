#ifndef __INC_MVDS_DISTRIBUTINGEVENTSLOT_HH__
#define __INC_MVDS_DISTRIBUTINGEVENTSLOT_HH__

#include "../EventSlot/eventslot.hh"
#include "../DeferedCall/deferedcall.hh"
#include "../EventDistributor/eventdistributor.hh"

namespace mvds {


  /**
   *
   *
   */
  template <typename... Args>
  class DistributingEventSlot : public EventSlot<Args...> {
  public:

    DistributingEventSlot(EventDistributor &distributor)
      : d_distributor(distributor) {}

    //    virtual ~DistributingEventSlot();

    // Add your public member functions here...

    // override
    virtual void signal(Args... args)
    {
      // Delete all handlers.
      for (auto i = EventSlot<Args...>::d_handlers.begin();
	   i != EventSlot<Args...>::d_handlers.end(); ++i)
	d_distributor.distribute(new DeferedCall<Args...>(*i,args...));
    }

  private:

    // Add your private members...

    EventDistributor &d_distributor;

  };

};


#endif // __INC_MVDS_DISTRIBUTINGEVENTSLOT_HH__

