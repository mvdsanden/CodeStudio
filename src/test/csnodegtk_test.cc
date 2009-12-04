#include <iostream>

#include "../CSNGtkMain/csngtkmain.hh"

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
  CSNode root(0,"root");

  CSNode *gtk = root.append(new CSNGtkMain(&root));

  root.append(new CSNode(&root));
  CSNode *n = root.append(new CSNode(&root,"n"));
  n->onChange().connect(call<CSNode*>(change));
  root.append(new CSNode(&root));

  n->setAttribute("Test","Bla");

  n->append(new CSNode(n,"Hoi","Hallo"));
  n->onUnload().connect(call<CSNode*>(unload));

  root.print(cout);

  sleep(1);

  gtk->setAttribute("title","Test");

  static_cast<CSNGtkMain*>(gtk)->join();

  return 0;
}
