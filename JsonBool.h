#ifndef JSON_BOOL_H
#define JSON_BOOL_H

#include "BaseJsonNode.h"

class JsonBool: public BaseJsonNode{
 public:
  JsonBool(bool pValue);
  JsonNodeType getType();
  std::string serialize();
  bool value();
 private:
  bool mValue;
};
  

#endif
