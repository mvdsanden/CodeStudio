#ifndef __INC_MVDS_CSNGTKVBOX_HH__
#define __INC_MVDS_CSNGTKVBOX_HH__

#include "../CSNGtkWidget/csngtkwidget.hh"
#include "../Factory/factory.hh"

namespace mvds {


  /**
   *
   *
   */
  class CSNGtkVBox : public CSNGtkWidget {

    void destroy();

  public:

    struct Fact : public Factory {
      virtual CSNode *operator()(CSNode *parent, std::string const &name, std::string const &value) const
      {
	return new CSNGtkVBox(parent,name,value);
      }
    };

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

