#include "gtkdistributor.ih"

#include <gtkmm/main.h>

GTKDistributor::GTKDistributor()
  : d_socketPair(Socket::pair())
{

}

