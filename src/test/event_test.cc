#include <iostream>

#include "../EventSlot/eventslot.hh"
#include "../MemberHandler/memberhandler.hh"
#include "../FunctionHandler/functionhandler.hh"

using namespace mvds;
using namespace std;

class Test {
public:

  void bla(int x, int y) { cout << x*y << endl; }

};

void bla(int x, int y) { cout << x+y << endl; }

int main()
{
  Test test;

  EventSlot<int,int> slot;

  slot.connect(call<int,int>(&Test::bla,test));
  slot.connect(call<int,int>(bla));

  slot.signal(2,3);

  return 0;
}
