#include "csngtkmain.ih"

#include "../GTKDistributor/gtkdistributor.hh"
#include "../MemberHandler/memberhandler.hh"
#include "../DistributingCall/distributingcall.hh"

int CSNGtkMain::main()
{
  Gtk::Main kit(0, 0);

  d_distributor = new GTKDistributor;

  onChange().connect(call<CSNode*>(*d_distributor,&CSNGtkMain::changed,*this));

  d_window = new Gtk::Window;

  d_window->set_title(attributeValue("title"));

  Gtk::Main::run(*d_window);

  return 0;
}
