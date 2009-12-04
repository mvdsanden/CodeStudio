#include "csngtkmain.ih"

CSNGtkMain::CSNGtkMain(CSNode *parent, std::string const &name)
  : CSNode(parent,name),
    d_distributor(0)
{
  // Add used attributes.
  setAttribute("nodeType","gtk");
  setAttribute("title","New Window");
  setAttribute("width","100");
  setAttribute("height","100");

  execute();
}

