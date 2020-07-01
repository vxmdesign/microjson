#include "JsonObject.h"

JsonObject::JsonObject(BaseJsonNode *pNode): BaseJsonList(pNode){
  mList.clear();
}

JsonNodeType JsonObject::getType(){
  return JSON_OBJECT;
}

unsigned int JsonObject::count(){
  return mList.size();
}

BaseJsonNode *JsonObject::getIndex(unsigned int pIndex){
  if(pIndex >= mList.size()){
    return NULL;
  }
  return mList[pIndex]->getValue();
}

JsonString *JsonObject::getKey(unsigned int pIndex){
  if(pIndex >= mList.size()){
    return NULL;
  }
  return mList[pIndex]->getKey();
}

BaseJsonNode *JsonObject::get(std::string &pKey){
  unsigned int c;
  for(c = 0;c < mList.size(); c++){
    if(mList[c]->getKey()->value() == pKey){
      return mList[c]->getValue();
    }
  }
  return NULL;
}

void JsonObject::addEntry(JsonObjEntry *pEntry){
  mList.push_back(pEntry);
}
  
std::string JsonObject::serialize(){
  std::string ret;
  unsigned int c;
  ret = "{";
  for(c = 0; c < mList.size(); c++){
    ret += mList[c]->serialize();
    if((c+1) < mList.size()){
      ret += ",";
    }    
  }
  ret += "}";
  return ret;
}
