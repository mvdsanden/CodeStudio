#include <iostream>

#include "../CSCom/cscom.hh"

#include "../MemberHandler/memberhandler.hh"
#include "../FunctionHandler/functionhandler.hh"

using namespace std;
using namespace mvds;

void unload(CSNode *node)
{
  cerr << "Unload";
  node->print(cerr,false);
  cerr << endl;
}

void change(CSNode *node)
{
  cerr << "Change";
  node->print(cerr,false);
  cerr << endl;
}

int main()
{
  CSCom com;

  CSNode *root = com.loadXML("../../test.xml","test");

  root->print(cout);

  return 0;
}
