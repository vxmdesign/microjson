#include "JsonObjEntry.h"

JsonObjEntry::JsonObjEntry(JsonString *pKey, BaseJsonNode *pValue){
  mKey = pKey;
  mValue = pValue;
}

JsonString * JsonObjEntry::getKey(){
  return mKey;
}

BaseJsonNode * JsonObjEntry::getValue(){
  return mValue;
}

std::string JsonObjEntry::serialize(){
  std::string ret;
  ret = mKey->serialize() + ":" + mValue->serialize();
  return ret;
}


