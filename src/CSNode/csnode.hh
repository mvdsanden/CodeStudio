#ifndef __INC_MVDS_CSNODE_HH__
#define __INC_MVDS_CSNODE_HH__

#include "../MutexLock/mutexlock.hh"
#include "../EventSlot/eventslot.hh"

#include "../MemberHandler/memberhandler.hh"

#include <string>
#include <map>
#include <list>

namespace mvds {

  class CSNode;

  typedef std::list<CSNode*> CSNodeList;
  typedef std::map<std::string,CSNode*> CSAttributes;

  /**
   *
   *
   */
  class CSNode {

    void copy(CSNode const &other);
    void destroy();

    CSNode(CSNode const &other); // NI

    CSNode &operator=(CSNode const &other); // NI

  public:

    /**
     *  @param parent the node's parent.
     *  @param name the node's name.
     */
    CSNode(CSNode *parent, std::string const &name = "", std::string const &value = "");

    ~CSNode() { destroy(); }


    // Add your public member functions here...

    /**
     *  @returns the node's parent (or zero if it doesn't have one).
     */
    CSNode *parent() { return d_parent; }

    /**
     *  @returns the children of the node.
     */
    CSNodeList const &children() const { return d_children; }

    /**
     *  Adds a node to the children.
     */
    CSNode *append(CSNode *node);

    /**
     *  Erases node from the children list.
     *
     *  node is not deleted.
     */
    void remove(CSNode *node);

    /**
     *  @returns the node's name (empty if unnamed).
     */
    std::string const &name() const { return d_name; }

    /**
     *  @returns the node's value.
     */
    std::string const &value() const { return d_value; }

    /**
     *  Sets the node's value.
     */
    void setValue(std::string const &value);

    /**
     *  @returns the attribute map.
     */
    CSAttributes const &attributes() const { return d_attributes; }

    /**
     *  @returns the node of the attribute with name.
     */
    CSNode const *attribute(std::string const &name) const;

    /**
     *  @returns the node of the attribute with name.
     */
    CSNode *attribute(std::string const &name);

    /**
     *  @returns the value of the attribute with name.
     */
    std::string attributeValue(std::string const &name) const;

    /**
     *  Sets attribute name to node value.
     */
    void setAttribute(std::string const &name, CSNode *value);

    /**
     *  Sets attribute name to string value.
     */
    void setAttribute(std::string const &name, std::string const &value);

    /**
     *  Lock this node.
     */
    bool lock() { return d_mutex.lock(); }

    /**
     *  Unlock this node.
     */
    bool unlock() { return d_mutex.unlock(); }

    /**
     *  @returns true if the node is active.
     */
    bool active() const { return d_active; }

    /**
     *  Activate or deactivate node.
     */
    void setActive(bool active);

    /**
     *  This is run once when a node is loaded.
     */
    void load() { d_onLoad.signal(this); }

    /**
     *  Triggered when the node is first loaded.
     */
    EventSlot<CSNode*> &onLoad() { return d_onLoad; }

    /**
     *  Triggered when the node is unloaded.
     */
    EventSlot<CSNode*> &onUnload() { return d_onUnload; }

    /**
     *  Triggered when the node has changed.
     */
    EventSlot<CSNode*> &onChange() { return d_onChange; }

    /**
     *  Triggered when the node is activated.
     *
     *  A node is activated when it becomes a causal part of the
     *  program, for instance when a gui component becomes visible
     *  to the user.
     */
    EventSlot<CSNode*> &onActivate() { return d_onActivate; }

    /**
     *  Triggered when the node is deactivated (@see onActivate).
     */
    EventSlot<CSNode*> &onDeactivate() { return d_onDeactivate; }

    /**
     *  Triggered if a child is appended to this node.
     */
    EventSlot<CSNode*,CSNode*> &onAppendChild() { return d_onAppendChild; }

    /**
     *  Triggered if a child is removed from this node.
     */
    EventSlot<CSNode*,CSNode*> &onRemoveChild() { return d_onAppendChild; }

    /**
     *  Triggered if one of the node's attributes is changed.
     */
    EventSlot<CSNode*,CSNode*> &onAttrChange() { return d_onAttrChange; }

    void print(std::ostream &stream, bool recursive = true) const;

  private:

    // Add your private members...

    std::string  d_name;
    std::string  d_value;
    bool         d_active;
    MutexLock    d_mutex;

    CSNode      *d_parent;
    CSNodeList   d_children;

    CSAttributes d_attributes;

    // Events

    EventSlot<CSNode*> d_onLoad;
    EventSlot<CSNode*> d_onUnload;
    EventSlot<CSNode*> d_onChange;
    EventSlot<CSNode*> d_onActivate;
    EventSlot<CSNode*> d_onDeactivate;
    EventSlot<CSNode*,CSNode*> d_onAppendChild;
    EventSlot<CSNode*,CSNode*> d_onRemoveChild;
    EventSlot<CSNode*,CSNode*> d_onAttrChange;

    // Event handlers
    void attributeChanged(CSNode *node)
    { d_onAttrChange.signal(this,node);
      d_onChange.signal(this); }

  };

  inline CSNode *CSNode::append(CSNode *node)
  {
    d_children.push_back(node);
    d_onAppendChild.signal(this,node);
    d_onChange.signal(this);
    return node;
  }

  inline void CSNode::remove(CSNode *node)
  {
    d_children.remove(node);
    d_onRemoveChild.signal(this,node);
    d_onChange.signal(this);
  }

  inline void CSNode::setValue(std::string const &value)
  {
    d_value = value;
    d_onChange.signal(this);
  }

  inline CSNode const *CSNode::attribute(std::string const &name) const
  {
    CSAttributes::const_iterator i = d_attributes.find(name);
    return (i == d_attributes.end()?0:(*i).second);
  }

  inline CSNode *CSNode::attribute(std::string const &name)
  {
    CSAttributes::iterator i = d_attributes.find(name);
    return (i == d_attributes.end()?0:(*i).second);
  }

  inline std::string CSNode::attributeValue(std::string const &name) const
  {
    CSAttributes::const_iterator i = d_attributes.find(name);
    return (i == d_attributes.end()?"":(*i).second->value());
  }

  inline void CSNode::setAttribute(std::string const &name, CSNode *value)
  {
    CSAttributes::iterator i = d_attributes.find(name);

    if (i != d_attributes.end() && (*i).second->parent() == this)
      delete (*i).second;

    value->onChange().connect(call<CSNode*>(&CSNode::attributeChanged,*this));

    d_attributes[name] = value;

    // Chould be a bit more efficient.
    attributeChanged(d_attributes[name]);
  }

  inline void CSNode::setAttribute(std::string const &name,
				   std::string const &value)
  {
    setAttribute(name,new CSNode(this,name,value));
  }

  inline void CSNode::setActive(bool active)
  {
    if (active != d_active) {
      d_active = active;
      d_onChange.signal(this);
      (d_active?d_onActivate:d_onDeactivate).signal(this);
    }
  }

};


#endif // __INC_MVDS_CSNODE_HH__

