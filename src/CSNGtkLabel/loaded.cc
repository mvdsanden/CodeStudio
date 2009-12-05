#include "csngtklabel.ih"

#include <iostream>

void CSNGtkLabel::loaded(CSNode *node)
{

  cerr << "Label loaded!" << endl;

  d_label = new Gtk::Label(value());

}
