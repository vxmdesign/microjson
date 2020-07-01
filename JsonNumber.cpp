#include "JsonNumber.h"

JsonNumber::JsonNumber(double pValue){
  mValue = pValue;
}

JsonNodeType JsonNumber::getType(){
  return JSON_NUMBER;
}

std::string JsonNumber::serialize(){
  char buf[20];
  sprintf(buf, "%f", mValue);
  return std::string(buf);
}

double JsonNumber::value(){
  return mValue;
}

bool JsonNumber::nodeEqual(BaseJsonNode *pNode){
  JsonNumber *tmp;
  tmp = (JsonNumber*)pNode;
  return mValue == tmp->mValue;
}
