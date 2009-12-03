#include "cscomparser.ih"

//#include <iostream>

void CSComParser::on_end_element(const Glib::ustring& name)
{
  //  cerr << "Close: " << name << "(" << d_current->name() << ")" << endl;

  if (d_current == d_root && name == "cscom")
	return;

  if (d_current->name() != name)
	throw std::runtime_error("closing tag mismatch");

  d_current = d_current->parent();

  if (!d_current)
	throw std::runtime_error("closed too many elements");
}
