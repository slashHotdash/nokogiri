#include <xml_cdata.h>

static void dealloc(xmlNodePtr node)
{
  if (node->doc == NULL) {
    NOKOGIRI_DEBUG_START_NODE(node);
    xmlFreeNode(node);
    NOKOGIRI_DEBUG_END(node);
  }
}

static VALUE new(VALUE klass, VALUE doc, VALUE content)
{
  xmlDocPtr xml_doc;
  Data_Get_Struct(doc, xmlDoc, xml_doc);

  xmlNodePtr node = xmlNewCDataBlock(
      xml_doc,
      (const xmlChar *)StringValuePtr(content),
      NUM2INT(rb_funcall(content, rb_intern("length"), 0))
  );

  VALUE rb_node = Data_Wrap_Struct(klass, NULL, dealloc, node);
  node->_private = (void *)rb_node;

  if(rb_block_given_p()) rb_yield(rb_node);

  return rb_node;
}

VALUE cNokogiriXmlCData;
void init_xml_cdata()
{
  VALUE nokogiri = rb_define_module("Nokogiri");
  VALUE xml = rb_define_module_under(nokogiri, "XML");
  VALUE klass = rb_define_class_under(xml, "CData", cNokogiriXmlNode);
  cNokogiriXmlCData = klass;

  rb_define_singleton_method(klass, "new", new, 2);
}
