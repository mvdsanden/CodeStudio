#include <iostream>

#include "../CSCom/cscom.hh"

#include "../MemberHandler/memberhandler.hh"
#include "../FunctionHandler/functionhandler.hh"

#include "../CSNGtkMain/csngtkmain.hh"
#include "../CSNGtkLabel/csngtklabel.hh"
#include "../CSNGtkVBox/csngtkvbox.hh"

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

  com.registerNodeType("gui",new CSNGtkMain::Fact);
  com.registerNodeType("vbox",new CSNGtkVBox::Fact);
  com.registerNodeType("label",new CSNGtkLabel::Fact);

  CSNode *test = new CSNode(0,"test");

  com.appendNamedNode(test,"bla");

  cout << "Bla: " << com.getNodeWithID("bla") << endl;

  delete test;

  cout << "Bla: " << com.getNodeWithID("bla") << endl;

  CSNode *root = com.loadXML("../../test.xml","test");

  root->print(cout);

  CSNode *label0 = com.getNodeWithID("label0");
  CSNode *label1 = com.getNodeWithID("label1");

  sleep(1);

  if (label0)
    label0->setValue("Changed!");
  else
    cerr << "Warning: node with id 'label0' not found." << endl;

  if (label1)
    label1->setValue("Wow! Cool");
  else
    cerr << "Warning: node with id 'label1' not found." << endl;

  CSNodeList gui = root->getNodesWithTag("gui");

  cout << "Found " << gui.size() << " gui nodes." << endl;

  if (!gui.empty())
    static_cast<CSNGtkMain*>(gui.front())->join();

  return 0;
}
