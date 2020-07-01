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

JsonNodeType JsonString::getType(){
  return JSON_STRING;
}

std::string JsonString::serialize(){
  return "\"" + mValue + "\"";  
}

std::string JsonString::value(){
  return mValue;
}

