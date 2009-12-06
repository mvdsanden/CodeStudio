#ifndef __INC_MVDS_CSNGTKLABEL_HH__
#define __INC_MVDS_CSNGTKLABEL_HH__

#include "../CSNGtkWidget/csngtkwidget.hh"

namespace mvds {


  /**
   *
   *
   */
  class CSNGtkLabel : public CSNGtkWidget {

    void copy(CSNGtkLabel const &other);
    void destroy();

  public:

    CSNGtkLabel(CSNode *parent, std::string const &name, std::string const &value = "");

    ~CSNGtkLabel();


    // Add your public member functions here...

    virtual Gtk::Widget *widget() { return d_label; }

  protected:

    virtual void loaded(CSNode *node);

  private:

    // Add your private members...

    Gtk::Label *d_label;

    void changed(CSNode *node) { d_label->set_text(value()); }

  };

  inline CSNGtkLabel::~CSNGtkLabel()
  {
    destroy();
  }

};


#endif // __INC_MVDS_CSNGTKLABEL_HH__

