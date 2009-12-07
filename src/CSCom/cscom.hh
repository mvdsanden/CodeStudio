#ifndef __INC_MVDS_CSCOM_HH__
#define __INC_MVDS_CSCOM_HH__

#include "../CSNode/csnode.hh"
#include "../Factory/factory.hh"

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
    void appendNamedNode(CSNode *node, std::string const &id);

    /**
     *  @returns the node with name id.
     */
    CSNode *getNodeWithID(std::string const &id);

    /**
     *  Load an XML.
     */
    CSNode *loadXML(std::string const &filename, std::string const &name);

    /**
     *  Register a factory for a new node type.
     */
    void registerNodeType(std::string const &name, Factory *factory);

    /**
     *  Creates a node of type.
     */
    CSNode *create(std::string const &type, CSNode *parent, std::string const &name, std::string const &value);

  private:

    // Add your private members...

    void unloadNamedNode(CSNode *node, std::string id);

    CSAttributes d_namedNodes;

    void parseWarning(std::string text);
    void parseError(std::string text);
    void parseFatal(std::string text);

    std::map<std::string,Factory *> d_factories;

  };

  inline CSCom::~CSCom()
  {
    destroy();
  }

};


#endif // __INC_MVDS_CSCOM_HH__

