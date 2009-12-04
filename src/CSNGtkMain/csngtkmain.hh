#ifndef __INC_MVDS_CSNGTKMAIN_HH__
#define __INC_MVDS_CSNGTKMAIN_HH__

#include "../CSNode/csnode.hh"
#include "../Thread/thread.hh"

#include "../EventDistributor/eventdistributor.hh"

#include <gtkmm.h>

namespace mvds {


  /**
   *
   *
   */
  class CSNGtkMain : public CSNode, public Thread {

    void copy(CSNGtkMain const &other);
    void destroy();

    CSNGtkMain(CSNGtkMain const &other); // NI

    CSNGtkMain &operator=(CSNGtkMain const &other); // NI

  public:

    CSNGtkMain(CSNode *parent, std::string const &name = "gtk");

    ~CSNGtkMain();

    // Add your public member functions here...

    virtual int main();

    void setTitle(std::string title);

  private:

    // Add your private members...
    EventDistributor *d_distributor;

    Gtk::Window *d_window;

    void changed(CSNode *node);

  };

  inline CSNGtkMain::~CSNGtkMain()
  {
    destroy();
  }

  inline void CSNGtkMain::setTitle(std::string title)
  {
    d_window->set_title(title);
  }

  inline void CSNGtkMain::changed(CSNode *node)
  {
    d_window->set_title(attributeValue("title"));
  }

};


#endif // __INC_MVDS_CSNGTKMAIN_HH__

