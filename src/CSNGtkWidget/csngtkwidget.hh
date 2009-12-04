#ifndef __INC_MVDS_CSNGTKWIDGET_HH__
#define __INC_MVDS_CSNGTKWIDGET_HH__

#include "../CSNode/csnode.hh"
#include "../CSNGtkMain/csngtkmain.hh"

namespace mvds {


  /**
   *
   *
   */
  class CSNGtkWidget : public CSNode {

    void copy(CSNGtkWidget const &other);
    void destroy();

  public:

    CSNGtkWidget(CSNode *parent, std::string const &name);

    ~CSNGtkWidget();

    // Add your public member functions here...

    virtual Gtk::Widget *widget() = 0;

  protected:

    virtual void loaded(CSNode *node) = 0;

  private:

    // Add your private members...

    CSNGtkMain *d_main;

  };

  inline CSNGtkWidget::~CSNGtkWidget()
  {
    destroy();
  }


};


#endif // __INC_MVDS_CSNGTKWIDGET_HH__

