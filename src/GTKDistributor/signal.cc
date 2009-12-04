#include "gtkdistributor.ih"

void GTKDistributor::signal()
{
  d_socketPair.first.write("1",1);
}
