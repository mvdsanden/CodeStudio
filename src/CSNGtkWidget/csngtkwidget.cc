#include "csngtkwidget.ih"

CSNGtkWidget::CSNGtkWidget(CSNode *parent, std::string const &name)
  : CSNode(parent,name),
    d_main(0)
{

  // Find gtk gui main
  for (CSNode *p = parent; p; p = p->parent()) {
    if (p->name() == "gui") {

      if (p->attributeValue("nodeType") != "gtk")
	throw runtime_error("mixing gui types");

      d_main = static_cast<CSNGtkMain*>(p);

      break;
    }
  }

  if (!d_main)
    throw runtime_error("should be in a subtree of gtk main");

  // Connect load event
  onLoad().connect(call<>(&CSNGtkWidget::loaded,*this));

}

