#include "csnode.ih"

CSNode::CSNode(CSNode *parent, std::string const &name, std::string const &value)
  : d_name(name), d_value(value), d_active(false), d_parent(parent)
{

  // Put your construction code here...

}

