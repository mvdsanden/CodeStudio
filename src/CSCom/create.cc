#include "cscom.ih"

CSNode *CSCom::create(std::string const &type,
		      CSNode *parent,
		      std::string const &name,
		      std::string const &value)
{
  auto i = d_factories.find(type);

  if (i == d_factories.end()) {
    parseWarning("unknown type '" + type + "'");
    return new CSNode(parent,name,value);
  }

  return (*(*i).second)(parent,name,value);
}
