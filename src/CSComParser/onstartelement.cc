#include "cscomparser.ih"

//#include <iostream>

void CSComParser::on_start_element(const Glib::ustring& name,
				   const AttributeList& properties)
{
  //  cerr << "Open: " << name << endl;

  if (!d_root) {
	if (name != "cscom")
	  throw runtime_error("error unexpected root tag");

	d_current = d_root = new CSNode(0,"root");
  } else {
    d_current = d_current->append(d_cscom.create(name,d_current,name,""));  
  }

  for(SaxParser::AttributeList::const_iterator i = properties.begin();
	  i != properties.end(); ++i) {
	d_current->setAttribute(i->name,i->value);
  }

  auto id = d_current->attributes().find("id");

  if (id != d_current->attributes().end())
    d_cscom.appendNamedNode(d_current,(*id).second->value());
}
