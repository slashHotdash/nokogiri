#ifndef NOKOGIRI_NATIVE
#define NOKOGIRI_NATIVE

#include <stdlib.h>
#include <ruby.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/xmlreader.h>
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>

#include <xml_document.h>
#include <html_document.h>
#include <xml_node.h>
#include <xml_text.h>
#include <xml_cdata.h>
#include <xml_node_set.h>
#include <xml_xpath.h>
#include <xml_xpath_context.h>
#include <xml_sax_parser.h>
#include <xml_reader.h>
#include <html_sax_parser.h>
#include <xslt_stylesheet.h>
#include <xml_syntax_error.h>

extern VALUE mNokogiri ;
extern VALUE mNokogiriXml ;
extern VALUE mNokogiriXmlSax ;
extern VALUE mNokogiriHtml ;
extern VALUE mNokogiriHtmlSax ;
extern VALUE mNokogiriXslt ;

#ifdef DEBUG

#define NOKOGIRI_DEBUG_START_NODE(p) if (getenv("NOKOGIRI_DEBUG")) fprintf(stderr,"\nnokogiri: %s:%d %p start node (%p %x %p/%s)\n", __FILE__, __LINE__, p, p->_private, p->type, p->name, p->name);
#define NOKOGIRI_DEBUG_START_TEXT(p) if (getenv("NOKOGIRI_DEBUG")) fprintf(stderr,"\nnokogiri: %s:%d %p start node (%p %x %p/%s) '%s'\n", __FILE__, __LINE__, p, p->_private, p->type, p->name, p->name, p->content);
#define NOKOGIRI_DEBUG_START(p) if (getenv("NOKOGIRI_DEBUG")) fprintf(stderr,"nokogiri: %s:%d %p start\n", __FILE__, __LINE__, p);
#define NOKOGIRI_DEBUG_END(p) if (getenv("NOKOGIRI_DEBUG")) fprintf(stderr,"nokogiri: %s:%d %p end\n", __FILE__, __LINE__, p);

#else

#define NOKOGIRI_DEBUG_START_NODE(p)
#define NOKOGIRI_DEBUG_START_TEXT(p)
#define NOKOGIRI_DEBUG_START(p)
#define NOKOGIRI_DEBUG_END(p)

#endif

#endif
