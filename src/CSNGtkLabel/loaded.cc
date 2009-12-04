#include "csngtklabel.ih"

void CSNGtkLabel::loaded(CSNode *node)
{

  d_label = new Gtk::Label(value());

}
