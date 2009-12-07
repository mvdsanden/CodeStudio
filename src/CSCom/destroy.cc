#include "cscom.ih"

void CSCom::destroy()
{

  for (auto i = d_namedNodes.begin(); i != d_namedNodes.end(); ++i)
	if (!(*i).second->parent())
	  delete (*i).second;

  d_namedNodes.clear();

  for (auto i = d_factories.begin(); i != d_factories.end(); ++i)
    delete (*i).second;

  d_factories.clear();

}

