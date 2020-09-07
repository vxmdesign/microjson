#include "JsonString.h"

JsonString::JsonString(std::string &pValue){
  unsigned int c;
  if(pValue[0] == '\"'){
    mValue = "";
    for(c = 1; c < pValue.size()-1; c++){
      mValue += pValue[c];
    }
  }else{
    mValue = pValue;
  }
}

JsonString::JsonString(const char *pValue){
  unsigned int c;
  std::string value;
  value = std::string(pValue);
  if(value[0] == '\"'){
    mValue = "";
    for(c = 1; c < value.size()-1; c++){
      mValue += value[c];
    }
  }else{
    mValue = value;
  }  
}

JsonNodeType JsonString::getType(){
  return JSON_STRING;
}

std::string JsonString::serialize(){
  return "\"" + mValue + "\"";  
}

std::string JsonString::value(){
  return mValue;
}

bool JsonString::nodeEqual(BaseJsonNode *pNode){
  JsonString *tmp;
  tmp = (JsonString*)pNode;
  return mValue == tmp->mValue;
}
