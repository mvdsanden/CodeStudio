#include "cscom.ih"

CSNode *CSCom::getNodeWithID(std::string const &id)
{
  auto i = d_namedNodes.find(id);

  if (i != d_namedNodes.end())
    return (*i).second;

  return 0;
}
