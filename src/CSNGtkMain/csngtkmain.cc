#include "csngtkmain.ih"

CSNGtkMain::CSNGtkMain(CSNode *parent, std::string const &name)
  : CSNode(parent,name),
    d_distributor(0)
{
  execute();
}

