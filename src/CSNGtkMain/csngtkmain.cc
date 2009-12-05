#include "csngtkmain.ih"

#include "../MemberHandler/memberhandler.hh"
#include "../DistributingCall/distributingcall.hh"

#include "../GTKDistributor/gtkdistributor.hh"

CSNGtkMain::CSNGtkMain(CSNode *parent, std::string const &name)
  : CSNode(parent,name),
    d_distributor(new GTKDistributor)
{
  // Add used attributes.
  setAttribute("nodeType","gtk");
  setAttribute("title","New Window");
  setAttribute("width","100");
  setAttribute("height","100");

  // Connect events
  //onAttrChange().connect(call<CSNode*,CSNode*>(*d_distributor,&CSNGtkMain::attrChanged,*this));
  attribute("title")->onChange().connect(call<CSNode*>(*d_distributor,&CSNGtkMain::titleChanged,*this));
  attribute("width")->onChange().connect(call<CSNode*>(*d_distributor,&CSNGtkMain::widthChanged,*this));
  attribute("height")->onChange().connect(call<CSNode*>(*d_distributor,&CSNGtkMain::heightChanged,*this));
  onAppendChild().connect(call<CSNode*,CSNode*>(*d_distributor,&CSNGtkMain::appendedChild,*this));

  execute();
}

