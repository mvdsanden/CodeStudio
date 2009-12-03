#include "cscom.ih"

void CSCom::destroy()
{

  // Put your destruction code here...

  for (CSAttributes::iterator i = d_namedNodes.begin();
	   i != d_namedNodes.end(); ++i) {

	if (!(*i).second->parent())
	  delete (*i).second;

  }

  d_namedNodes.clear();
}

