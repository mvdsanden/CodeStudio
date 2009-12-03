#ifndef __INC_MVDS_CSCOM_HH__
#define __INC_MVDS_CSCOM_HH__

#include "../CSNode/csnode.hh"

namespace mvds {


  /**
   *
   *
   */
  class CSCom {

    void copy(CSCom const &other);
    void destroy();

    CSCom(CSCom const &other); // NI

    CSCom &operator=(CSCom const &other); // NI

  public:

    CSCom();

    ~CSCom();

    // Add your public member functions here...

	/**
	 *  Add a named node to the global directory.
	 */
	void appendNamedNode(CSNode *node);

	/**
	 *  Load a XML.
	 */
	CSNode *loadXML(std::string const &filename, std::string const &name);

  private:

    // Add your private members...

	CSAttributes d_namedNodes;

	void parseWarning(std::string text);
	void parseError(std::string text);
	void parseFatal(std::string text);

  };

  inline CSCom::~CSCom()
  {
    destroy();
  }

  inline void CSCom::appendNamedNode(CSNode *node)
  {
	d_namedNodes[node->name()] = node;
  }

};


#endif // __INC_MVDS_CSCOM_HH__

