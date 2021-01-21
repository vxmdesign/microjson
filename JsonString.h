#ifndef JSON_STRING_H
#define JSON_STRING_H

#include <string>
#include "BaseJsonNode.h"

class JsonString: public BaseJsonNode{
 public:
  JsonString(std::string &pValue);
  JsonString(const char *pValue);
  JsonNodeType getType();
  std::string serialize();
  void setValue(std::string pValue);
  std::string value();
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  std::string mValue;
};


#endif
