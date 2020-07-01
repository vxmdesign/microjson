#ifndef JSON_STRING_H
#define JSON_STRING_H

#include <string>
#include "BaseJsonNode.h"

class JsonString: public BaseJsonNode{
 public:
  JsonString(std::string &pValue);
  JsonNodeType getType();
  std::string serialize();
  std::string value();
 private:
  std::string mValue;
};


#endif
