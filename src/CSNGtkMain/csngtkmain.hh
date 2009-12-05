#ifndef __INC_MVDS_CSNGTKMAIN_HH__
#define __INC_MVDS_CSNGTKMAIN_HH__

#include "../CSNode/csnode.hh"
#include "../Thread/thread.hh"

#include "../EventDistributor/eventdistributor.hh"

#include <gtkmm.h>

namespace mvds {


  /**
   *  The GTK GUI Main.
   *
   */
  class CSNGtkMain : public CSNode, public Thread {

    void copy(CSNGtkMain const &other);
    void destroy();

    CSNGtkMain(CSNGtkMain const &other); // NI

    CSNGtkMain &operator=(CSNGtkMain const &other); // NI

  public:

    CSNGtkMain(CSNode *parent, std::string const &name = "gui");

    ~CSNGtkMain();

    // Add your public member functions here...

    virtual int main();

    void setTitle(std::string const &title);

    EventDistributor *distributor() { return d_distributor; }

  private:

    // Add your private members...
    EventDistributor *d_distributor;

    Gtk::Window *d_window;

    void changed(CSNode *node);

    void titleChanged(CSNode *node)  { d_window->set_title(node->value()); }
    void widthChanged(CSNode *node)  { d_window->resize(atof(node->value().c_str()),d_window->get_height()); }
    void heightChanged(CSNode *node) { d_window->resize(d_window->get_width(),atof(node->value().c_str())); }

    void appendedChild(CSNode *node, CSNode *child);
  };

  inline CSNGtkMain::~CSNGtkMain()
  {
    destroy();
  }

  inline void CSNGtkMain::setTitle(std::string const &title)
  {
    attribute("title")->setValue(title);
    d_window->set_title(title);
  }

  inline void CSNGtkMain::changed(CSNode *node)
  {
    d_window->set_title(attributeValue("title"));
  }

};


#endif // __INC_MVDS_CSNGTKMAIN_HH__

