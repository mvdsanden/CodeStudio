#include "csngtklabel.ih"

#include "../DistributingCall/distributingcall.hh"

CSNGtkLabel::CSNGtkLabel(CSNode *parent, std::string const &name, std::string const &value)
  : CSNGtkWidget(parent,name,value)
{
  setAttribute("widget","vbox");

  onChange().connect(call<CSNode*>(*d_main->distributor(),&CSNGtkLabel::changed,*this));
}

