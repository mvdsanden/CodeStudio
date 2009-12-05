#include "gtkdistributor.ih"

bool GTKDistributor::onSignal(Glib::IOCondition condition)
{
  // Read the data on the socket.
  char buffer[1];
  d_socketPair.second.read(buffer,1);

  d_mutex.lock();
  {

    while (!d_queue.empty()) {
      cerr << "Executing event: " << d_queue.front() << endl;
      (*d_queue.front())();
      delete d_queue.front();
      d_queue.pop();
    }

  }
  d_mutex.unlock();

  return true;
}

