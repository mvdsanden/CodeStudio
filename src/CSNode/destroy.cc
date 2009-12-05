#include "csnode.ih"

#include <iostream>

void CSNode::destroy()
{
  // Put your destruction code here...

  d_onUnload.signal(this);

  // Delete all children that have this node as their parent.
  for (CSNodeList::iterator i = d_children.begin();
       i != d_children.end(); ++i) {
    cerr << name() << " deletes " << (*i)->name() << endl;

    if ((*i)->parent() == this)
      delete *i;
  }

  // Clear the list.
  d_children.clear();

  // Delete all children that have this node as their parent.
  for (CSAttributes::iterator i = d_attributes.begin();
	   i != d_attributes.end(); ++i)
	if ((*i).second->parent() == this)
	  delete (*i).second;

  // Clear the list.
  d_attributes.clear();


}

