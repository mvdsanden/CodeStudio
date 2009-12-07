#include "cscom.ih"

void CSCom::unloadNamedNode(CSNode *node, std::string id)
{
  auto i = d_namedNodes.find(id);

  if (i != d_namedNodes.end())
    d_namedNodes.erase(i);
}
