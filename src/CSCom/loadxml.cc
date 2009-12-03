#include "cscom.ih"

#include <string>

#include "../CSComParser/cscomparser.hh"

#include "../MemberHandler/memberhandler.hh"
#include "../FunctionHandler/functionhandler.hh"

CSNode *CSCom::loadXML(std::string const &filename, std::string const &name)
{
  CSComParser parser;

  parser.onWarning().connect(call<string>(&CSCom::parseWarning,*this));
  parser.onError().connect(call<string>(&CSCom::parseError,*this));
  parser.onFatal().connect(call<string>(&CSCom::parseFatal,*this));

  try {
	// Parse the file.
	parser.set_substitute_entities(true);
	parser.parse_file(filename);
  } catch(const xmlpp::exception& ex) {

	cerr << "libxml++ exception: " << ex.what() << endl;

  } catch(runtime_error &e) {

	cerr << "CSComParser exception: " << e.what() << endl;

  }

  // Delete if it already exists.
  if (d_namedNodes.find(name) != d_namedNodes.end())
	delete d_namedNodes[name];

  d_namedNodes[name] = parser.root();

  return parser.root();
}

