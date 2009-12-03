#ifndef __INC_MVDS_PLUGIN_HH__
#define __INC_MVDS_PLUGIN_HH__

namespace mvds {


  /**
   *  The Plugin Interface.
   *
   */
  class Plugin {
  public:

	virtual std::string const &name() const = 0;

	virtual void init(CSCom &cscom) = 0;

  private:
  };

};


#endif // __INC_MVDS_PLUGIN_HH__

