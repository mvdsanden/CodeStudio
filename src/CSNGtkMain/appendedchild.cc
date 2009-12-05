#include "csngtkmain.ih"

#include "../CSNGtkWidget/csngtkwidget.hh"

#include <iostream>

void CSNGtkMain::appendedChild(CSNode *node, CSNode *child)
{

  if (child->attributeValue("nodeType") == "GtkWidget") {

    cerr << "Adding widget" << endl;

    d_window->add(*static_cast<CSNGtkWidget*>(child)->widget());

  }

}
