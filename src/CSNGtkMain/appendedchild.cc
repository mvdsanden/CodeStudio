#include "csngtkmain.ih"

#include "../CSNGtkWidget/csngtkwidget.hh"

void CSNGtkMain::appendedChild(CSNode *node, CSNode *child)
{

  if (child->attributeValue("nodeType") == "GtkWidget") {

    d_window->add(*static_cast<CSNGtkWidget*>(child)->widget());

  }

}
