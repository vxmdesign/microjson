#include "JsonRoot.h"

JsonRoot::JsonRoot(){
  mNode = NULL; 
}

JsonRoot::~JsonRoot(){
  if(mNode != NULL){
    delete mNode;
  }
}

JsonNodeType JsonRoot::getType(){
  return JSON_ROOT;
}

std::string JsonRoot::serialize(){
  if(mNode != NULL){
    return mNode->serialize();
  }
  return std::string("");
}

void JsonRoot::setNode(BaseJsonNode *pNode){
  mNode = pNode;
}

BaseJsonNode* JsonRoot::getNode(){
  return mNode;
}

bool JsonRoot::nodeEqual(BaseJsonNode *pNode){
  JsonRoot *tmp;
  tmp = (JsonRoot*)pNode;
  return mNode->equals(tmp->mNode);
}
