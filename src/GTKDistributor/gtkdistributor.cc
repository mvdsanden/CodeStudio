#include "gtkdistributor.ih"

#include <gtkmm/main.h>

GTKDistributor::GTKDistributor()
  : d_socketPair(Socket::pair())
{
  // Connect the signal method to the ready to read event of the second socket.
  d_sigCon = Glib::signal_io().connect(sigc::mem_fun(this,&GTKDistributor::onSignal),
							 d_socketPair.second.fd(),
							 Glib::IO_IN);
}

