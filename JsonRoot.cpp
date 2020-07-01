#include "JsonRoot.h"

JsonRoot::JsonRoot(){
  mNode = NULL; 
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


