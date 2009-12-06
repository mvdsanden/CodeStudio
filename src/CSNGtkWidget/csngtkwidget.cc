#include "csngtkwidget.ih"

#include "../DeferedCall/deferedcall.hh"

#include <iostream>

CSNGtkWidget::CSNGtkWidget(CSNode *parent, std::string const &name, std::string const &value)
  : CSNode(parent,name,value),
    d_main(0)
{

  setAttribute("nodeType","GtkWidget");

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
    throw runtime_error("widgets should be in a subtree of gui");

  // Connect load event
  onLoad().connect(call<>(&CSNGtkWidget::loaded,*this));

  cerr << "Distributing load!" << endl;
  d_main->distributor()->distribute(call<CSNode*>(&CSNGtkWidget::loaded,*this,this));

}

