#include "cscom.ih"

void CSCom::registerNodeType(std::string const &name, Factory *factory)
{

  if (d_factories.find(name) != d_factories.end())
    throw runtime_error("Node type '" + name + "' already registered");

  d_factories[name] = factory;

}
