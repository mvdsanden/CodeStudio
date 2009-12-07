#ifndef __INC_MVDS_CSCOMPARSER_HH__
#define __INC_MVDS_CSCOMPARSER_HH__

#include "../CSNode/csnode.hh"
#include "../EventSlot/eventslot.hh"

#include "../CSCom/cscom.hh"

#include <stdexcept>
#include <libxml++/libxml++.h>

namespace mvds {

  class CSComParser : public xmlpp::SaxParser
  {
  public:

	CSComParser(CSCom &cscom);

	virtual ~CSComParser();

	CSNode *root() { return d_root; }

	EventSlot<std::string> &onWarning() { return d_onWarning; }
	EventSlot<std::string> &onError()   { return d_onError; }
	EventSlot<std::string> &onFatal()   { return d_onFatal; }

  protected:

	//overrides:
	virtual void on_start_document();
	virtual void on_end_document();
	virtual void on_start_element(const Glib::ustring& name,
                                const AttributeList& properties);
	virtual void on_end_element(const Glib::ustring& name);
	virtual void on_characters(const Glib::ustring& characters);
	virtual void on_comment(const Glib::ustring& text);
	virtual void on_warning(const Glib::ustring& text);
	virtual void on_error(const Glib::ustring& text);
	virtual void on_fatal_error(const Glib::ustring& text);

  private:

    CSCom &d_cscom;

    CSNode *d_root;
    CSNode *d_current;

    EventSlot<std::string> d_onWarning;
    EventSlot<std::string> d_onError;
    EventSlot<std::string> d_onFatal;

  };

  inline CSComParser::CSComParser(CSCom &cscom)
    : d_cscom(cscom),
      d_root(0),
      d_current(0)
  {
  }

  inline CSComParser::~CSComParser()
  {
  }

  inline void CSComParser::on_start_document()
  {
  }

  inline void CSComParser::on_end_document()
  {
  }

  inline void CSComParser::on_characters(const Glib::ustring& characters)
  {
	d_current->setValue(d_current->value() + characters);
  }

  inline void CSComParser::on_comment(const Glib::ustring& text)
  {
  }

  inline void CSComParser::on_warning(const Glib::ustring& text)
  {
	d_onWarning.signal(text);
  }

  inline void CSComParser::on_error(const Glib::ustring& text)
  {
	d_onError.signal(text);
  }

  inline void CSComParser::on_fatal_error(const Glib::ustring& text)
  {
	d_onFatal.signal(text);
  }

};

#endif // __INC_MVDS_CSCOMPARSER_HH__
