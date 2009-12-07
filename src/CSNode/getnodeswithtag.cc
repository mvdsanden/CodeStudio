#include "csnode.ih"

CSNodeList CSNode::getNodesWithTag(std::string const &tag)
{
  CSNodeList res;

  for (auto i = d_children.begin(); i != d_children.end(); ++i)
    if ((*i)->name() == tag)
      res.push_back(*i);

  return res;
}
