#include <iostream>

#include "../EventSlot/eventslot.hh"
#include "../FunctionHandler/functionhandler.hh"
#include "../DistributingEventSlot/distributingeventslot.hh"
#include "../DistributingCall/distributingcall.hh"

#include <vector>

using namespace std;
using namespace mvds;

void test(int a, string test)
{
  cout << a << ":" << test << endl;
}

class Dist : public EventDistributor {
public:

  virtual void distribute(EventHandler<> *handler)
  {
    d_events.push_back(handler);
  }

  void run()
  {
    for (auto i = d_events.rbegin(); i != d_events.rend(); ++i)
      (**i)();
  }

private:

  std::vector<EventHandler<> *> d_events;

};

int main()
{
  Dist dist;

  DistributingEventSlot<int,string> onTest(dist);

  EventSlot<int,string> onHello;

  onTest.connect(call<int,string>(&test));

  onHello.connect(call<int,string>(dist,&test));

  onTest.signal(6,"bla");
  onTest.signal(7,"test");
  onTest.signal(8,"hello");

  onHello.signal(9,"blabla");
  onHello.signal(10,"hahaha");

  dist.run();

  return 0;
}
