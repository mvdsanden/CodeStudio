#ifndef __INC_MVDS_CSNGTKVBOX_HH__
#define __INC_MVDS_CSNGTKVBOX_HH__

#include "../CSNGtkWidget/csngtkwidget.hh"

namespace mvds {


  /**
   *
   *
   */
  class CSNGtkVBox : public CSNGtkWidget {

    void destroy();

  public:

    CSNGtkVBox(CSNode *parent, std::string const &name, std::string const &value = "");

    ~CSNGtkVBox() { destroy(); }

    // Add your public member functions here...

    virtual Gtk::Widget *widget() { return d_vbox; }

  protected:

    virtual void loaded(CSNode *node);

  private:

    // Add your private members...

    Gtk::VBox *d_vbox;

    void appendedChild(CSNode *node, CSNode *child);

  };

};


#endif // __INC_MVDS_CSNGTKVBOX_HH__

