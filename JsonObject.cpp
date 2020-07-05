#include "JsonObject.h"

JsonObject::JsonObject(BaseJsonNode *pNode): BaseJsonList(pNode){
  mList.clear();
}

JsonObject::~JsonObject(){
  unsigned int c;
  for(c = 0; c < mList.size(); c++){
    delete mList[c];
  }
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

void JsonObject::addEntry(std::string &pKey, std::string &pValue){
  JsonObjEntry *joe;
  joe = new JsonObjEntry(new JsonString(pKey), new JsonString(pValue));
  addEntry(joe);		      
}

void JsonObject::addEntry(std::string &pKey, double pValue){
  JsonObjEntry *joe;
  joe = new JsonObjEntry(new JsonString(pKey), new JsonNumber(pValue));
  addEntry(joe);
}

void JsonObject::addEntry(std::string &pKey, bool pValue){
  JsonObjEntry *joe;
  joe = new JsonObjEntry(new JsonString(pKey), new JsonBool(pValue));
  addEntry(joe);
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

bool JsonObject::nodeEqual(BaseJsonNode *pNode){
  JsonObject *tmp;
  unsigned int c;
  BaseJsonNode *val;
  std::string key;
  tmp = (JsonObject*)pNode;
  if(mList.size() != tmp->mList.size()){
    return false;
  }
  for(c = 0; c < mList.size(); c++){
    key = getKey(c)->value();
    val = tmp->get(key);
    if(val->equals(getIndex(c))== false){
      return false;
    }
  }
  return true;
}
