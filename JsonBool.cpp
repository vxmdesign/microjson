#include "JsonBool.h"

JsonBool::JsonBool(bool pValue){
  mValue = pValue;  
}

JsonNodeType JsonBool::getType(){
  return JSON_BOOL;
}

std::string JsonBool::serialize(){
  if(mValue){
    return std::string("true");
  }
  return std::string("false");      
}

bool JsonBool::value(){
  return mValue;
}

void JsonBool::setValue(bool pValue){
  mValue = pValue;
}

bool JsonBool::nodeEqual(BaseJsonNode *pNode){
  JsonBool *tmp;
  tmp = (JsonBool*)pNode;
  return mValue== tmp->mValue;
}
