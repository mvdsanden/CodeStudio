#include "csngtkmain.ih"

void CSNGtkMain::destroy()
{

  // Put your destruction code here...

  if (d_distributor) {
    delete d_distributor;
    d_distributor = 0;
  }

}

