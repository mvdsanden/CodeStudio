#include "csngtkmain.ih"

#include "../MemberHandler/memberhandler.hh"
#include "../DistributingCall/distributingcall.hh"

#include "../GTKDistributor/gtkdistributor.hh"

int CSNGtkMain::main()
{
  Gtk::Main kit(0, 0);

  // Initialize this side of the distributor.
  static_cast<GTKDistributor*>(d_distributor)->initialize();


  d_window = new Gtk::Window;

  // Set window title
  d_window->set_title(attributeValue("title"));


  //  for (auto i = children().begin(); i != children().end(); ++i)
  //    appendedChild(this,*i);

  Gtk::Main::run(*d_window);

  delete d_window;

  return 0;
}
