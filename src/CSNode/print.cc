#include "csnode.ih"

#include <iostream>

void CSNode::print(std::ostream &stream, bool recursive) const
{

  stream << "<" << d_name;

  if (!d_attributes.empty())
	stream << " ";

  for (CSAttributes::const_iterator i = d_attributes.begin();
	   i != d_attributes.end(); ++i) {

	if (i != d_attributes.begin())
	  stream << " ";

	stream << (*i).first << "=" << "{";
	(*i).second->print(stream,recursive);
	stream << "}";

  }

  stream << ">" << d_value;

  for (CSNodeList::const_iterator i = d_children.begin();
	   i != d_children.end(); ++i) {
	(*i)->print(stream,recursive);
	stream << endl;
  }

  stream << "</" << d_name << ">";

}
