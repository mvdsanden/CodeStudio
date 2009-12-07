#include "cscom.ih"

#include "../MemberHandler/memberhandler.hh"
#include "../BindHandler/bindhandler.hh"

void CSCom::appendNamedNode(CSNode *node, std::string const &id)
{
  d_namedNodes[id] = node;
  node->onUnload().connect(bindAfter<CSNode*>(call<CSNode*,std::string>(&CSCom::unloadNamedNode,*this),id));
}
