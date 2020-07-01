#include "JsonArray.h"

JsonArray::JsonArray(BaseJsonNode *pParent): BaseJsonList(pParent){
  mList.clear();
}

JsonNodeType JsonArray::getType(){
  return JSON_ARRAY;
}

std::string JsonArray::serialize(){
  std::string ret;
  unsigned int c;
  ret = "[";
  for(c = 0; c < mList.size(); c++){
    ret += mList[c]->serialize();
    if((c+1) < mList.size()){
      ret += ",";
    }     
  }
  ret += "]";
  return ret;
}

unsigned int JsonArray::count(){
  return mList.size();
}

BaseJsonNode * JsonArray::getIndex(unsigned int pIndex){
  if(pIndex >= mList.size()){
    return NULL;
  }
  return mList[pIndex];
}

void JsonArray::addNode(BaseJsonNode *pNode){
  mList.push_back(pNode);
}
