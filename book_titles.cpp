#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

void printTitles(xmlNode *node) {
  for (xmlNode *cur = node; cur != nullptr; cur = cur->next) {
    if (cur->type == XML_ELEMENT_NODE) {
      if (xmlStrcmp(cur->name, BAD_CAST "title") == 0) {
        xmlChar *content = xmlNodeGetContent(cur);
        if (content) {
          std::cout << (const char*)content << std::endl;
          xmlFree(content);
        }
      }
    }
    printTitles(cur->children);
  }
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <xmlfile>" <<
std::endl;
    return 1;
  }
  const char *filename = argv[1];
  
  xmlDoc *doc = xmlReadFile(filename, nullptr, 0);
  if (doc == nullptr) {
    std::cerr << "Error: could not parse XML file: " << filename
<< std::endl;
    return 1;
  }
  xmlNode *root = xmlDocGetRootElement(doc);
  if (root == nullptr) {
    std::cerr << "Error: empty XML document." << std::endl;
    xmlFreeDoc(doc);
    return 1;
  }
  std::cout << "Book titles:" << std::endl;
  printTitles(root);
  xmlFreeDoc(doc);
  xmlCleanupParser();
  return 0;
}
