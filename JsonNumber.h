#ifndef JSON_NUMBER_H
#define JSON_NUMBER_H

#include <stdio.h>
#include "BaseJsonNode.h"

class JsonNumber: public BaseJsonNode{
 public:
  JsonNumber(double pValue);
  JsonNumber(int pValue);
  JsonNodeType getType();
  std::string serialize();
  void setValue(int pValue);
  void setValue(double pValue);
  double value();
  int ivalue();
  bool isInt();
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  double mValue;
  int mIValue;
  bool mInt;
};

#endif
