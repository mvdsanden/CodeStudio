#include <iostream>

#include "../CSNGtkMain/csngtkmain.hh"
#include "../CSNGtkLabel/csngtklabel.hh"
#include "../CSNGtkVBox/csngtkvbox.hh"

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

  //  root.append(new CSNode(&root));
  //  CSNode *n = root.append(new CSNode(&root,"n"));
  //  n->onChange().connect(call<CSNode*>(change));
  //  root.append(new CSNode(&root));

  //  n->setAttribute("Test","Bla");

  //  n->append(new CSNode(n,"Hoi","Hallo"));
  //  n->onUnload().connect(call<CSNode*>(unload));

  root.print(cout);

  CSNode *vbox0 = gtk->append(new CSNGtkVBox(gtk,"VBox0"));

  CSNode *label0 = vbox0->append(new CSNGtkLabel(vbox0,"Label0","Label0"));
  CSNode *label1 = vbox0->append(new CSNGtkLabel(vbox0,"Label1","Label1"));
  CSNode *label2 = vbox0->append(new CSNGtkLabel(vbox0,"Label2","Label2"));

  sleep(1);

  label0->setValue("test");
  label1->setValue("hallo");
  label2->setValue("En? Werkt het?");

  gtk->attribute("title")->setValue("Test");
  gtk->attribute("height")->setValue("600");
  gtk->attribute("width")->setValue("800");

  static_cast<CSNGtkMain*>(gtk)->join();

  return 0;
}
