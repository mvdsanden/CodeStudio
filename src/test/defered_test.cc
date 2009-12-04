#include <iostream>

#include "../EventSlot/eventslot.hh"
#include "../FunctionHandler/functionhandler.hh"
#include "../DeferedCall/deferedcall.hh"

using namespace std;
using namespace mvds;

void test(int a, string test)
{
  cout << a << ":" << test << endl;
}

int main()
{
  EventSlot<> onTest;

  onTest.connect(call<int,string>(&test,6,"bla"));

  onTest.signal();

  return 0;
}
