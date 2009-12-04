#include "csngtkmain.ih"

#include "../GTKDistributor/gtkdistributor.hh"
#include "../MemberHandler/memberhandler.hh"
#include "../DistributingCall/distributingcall.hh"

int CSNGtkMain::main()
{
  Gtk::Main kit(0, 0);

  d_distributor = new GTKDistributor;

  // Connect events
  //onAttrChange().connect(call<CSNode*,CSNode*>(*d_distributor,&CSNGtkMain::attrChanged,*this));
  attribute("title")->onChange().connect(call<CSNode*>(*d_distributor,&CSNGtkMain::titleChanged,*this));
  attribute("width")->onChange().connect(call<CSNode*>(*d_distributor,&CSNGtkMain::widthChanged,*this));
  attribute("height")->onChange().connect(call<CSNode*>(*d_distributor,&CSNGtkMain::heightChanged,*this));
  onAppendChild().connect(call<CSNode*,CSNode*>(*d_distributor,&CSNGtkMain::appendedChild,*this));

  d_window = new Gtk::Window;

  // Set window title
  d_window->set_title(attributeValue("title"));

  for (auto i = children().begin(); i != children().end(); ++i)
    appendedChild(this,*i);

  Gtk::Main::run(*d_window);

  return 0;
}
