#include "csngtkvbox.ih"

#include "../DistributingCall/distributingcall.hh"

CSNGtkVBox::CSNGtkVBox(CSNode *parent, std::string const &name, std::string const &value)
  : CSNGtkWidget(parent,name,value)
{
  setAttribute("widget","vbox");

  onAppendChild().connect(call<CSNode*,CSNode*>(*d_main->distributor(),&CSNGtkVBox::appendedChild,*this));
}
