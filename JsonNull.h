#ifndef JSON_NULL_H
#define JSON_NULL_H

#include "BaseJsonNode.h"

class JsonNull: public BaseJsonNode{
 public:
  JsonNull();
  JsonNodeType getType();
  std::string serialize();  
};

#endif
