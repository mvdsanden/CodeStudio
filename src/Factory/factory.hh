#ifndef __INC_MVDS_FACTORY_HH__
#define __INC_MVDS_FACTORY_HH__

#include "../CSNode/csnode.hh"

#include <string>

namespace mvds {


  /**
   *  Baseclass for CSNode factories
   */
  class Factory {
  public:
    virtual CSNode *operator()(CSNode *parent, std::string const &name, std::string const &value) const = 0;  };

};


#endif // __INC_MVDS_FACTORY_HH__

