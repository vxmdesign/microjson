#include "JsonDriver.h"

JSON::JsonDriver::JsonDriver(){
  mRoot = NULL;
  mCurrent = NULL;
}

JSON::JsonDriver::~JsonDriver(){
}

JsonRoot* JSON::JsonDriver::parse(std::string &pInput){
  JSON::JsonScanner *scanner;
  JSON::JsonParser *parser;
  int ret;
  mRoot = new JsonRoot();
  mCurrent = mRoot;  
  std::istringstream sin(pInput);
  scanner = new JSON::JsonScanner(&sin);
  parser = new JSON::JsonParser(scanner, this);  
  ret = parser->parse();
  delete scanner;
  delete parser;
  if(ret != 0){
    delete mRoot;
    return NULL;
  }
  return mRoot;
}

void JSON::JsonDriver::pushObject(){
  JsonObject *ret;
  if(mCurrent == NULL){
    return;
  }  
  ret = new JsonObject(mCurrent);
  if(mRoot == mCurrent){
    mRoot->setNode(ret);
  }
  mCurrent = ret;
}

void JSON::JsonDriver::pushArray(){
  JsonArray *ret;
  if(mCurrent == NULL){
    return;
  }
  ret = new JsonArray(mCurrent);
  if(mRoot == mCurrent){
    mRoot->setNode(ret);
  }
  mCurrent = ret;
}

JsonObject * JSON::JsonDriver::popObject(){
  JsonObject *tmp;
  tmp = dynamic_cast<JsonObject*>(mCurrent);
  if(tmp == NULL){
    return NULL;
  }
  mCurrent = tmp->getParent();
  return tmp;
}

JsonArray * JSON::JsonDriver::popArray(){
  JsonArray *tmp;
  tmp = dynamic_cast<JsonArray*>(mCurrent);
  if(tmp == NULL){
    return NULL;
  }
  mCurrent = tmp->getParent();
  return tmp;
}

int JSON::JsonDriver::insert(JsonObjEntry *pEntry){
  if(mCurrent->getType() != JSON_OBJECT){
    return -1;
  }
  ((JsonObject*)mCurrent)->addEntry(pEntry);
  return 0;
}


int JSON::JsonDriver::insert(BaseJsonNode *pNode){
  if(mCurrent->getType() != JSON_ARRAY){
    return -1;
  }
  ((JsonArray*)mCurrent)->addNode(pNode);
  return 0;
}

