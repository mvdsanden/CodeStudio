#include "csngtklabel.ih"

#include <iostream>

void CSNGtkLabel::loaded(CSNode *node)
{

  d_label = new Gtk::Label(value());

}
