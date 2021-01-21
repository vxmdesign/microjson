#include "JsonNumber.h"

JsonNumber::JsonNumber(double pValue){
  mValue = pValue;
  mInt = false;
}

JsonNumber::JsonNumber(int pValue){
  mIValue = pValue;
  mInt = true;
}

JsonNodeType JsonNumber::getType(){
  return JSON_NUMBER;
}

std::string JsonNumber::serialize(){
  char buf[20];
  if(mInt == false){
    sprintf(buf, "%f", mValue);
    return std::string(buf);
  }
  sprintf(buf, "%d", mIValue);
  return std::string(buf);
}

double JsonNumber::value(){
  if(mInt == false){
    return mValue;
  }
  return (double)mIValue;
}

void JsonNumber::setValue(int pValue){
  mInt = true;
  mIValue = pValue;
}

void JsonNumber::setValue(double pValue){
  mInt = false;
  mValue = pValue;
}

int JsonNumber::ivalue(){
  if(mInt == true){
    return mIValue;
  }
  return (int)mValue;
}

bool JsonNumber::isInt(){
  return mInt;
}

bool JsonNumber::nodeEqual(BaseJsonNode *pNode){
  JsonNumber *tmp;
  tmp = (JsonNumber*)pNode;
  return mValue == tmp->mValue;
}
