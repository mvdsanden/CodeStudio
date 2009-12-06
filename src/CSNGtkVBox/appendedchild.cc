#include "csngtkvbox.ih"

void CSNGtkVBox::appendedChild(CSNode *node, CSNode *child)
{

  if (child->attributeValue("nodeType") == "GtkWidget") {

    d_vbox->add(*static_cast<CSNGtkWidget*>(child)->widget());

    d_vbox->show_all_children();

  }


}
