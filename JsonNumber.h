#ifndef JSON_NUMBER_H
#define JSON_NUMBER_H

#include <stdio.h>
#include "BaseJsonNode.h"

class JsonNumber: public BaseJsonNode{
 public:
  JsonNumber(double pValue);
  JsonNodeType getType();
  std::string serialize();
  double value();
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  double mValue;
};

#endif
