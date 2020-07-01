#ifndef JSON_ROOT_H
#define JSON_ROOT_H

#include "BaseJsonNode.h"

class JsonRoot: public BaseJsonNode{
 public:
  JsonRoot();
  JsonNodeType getType();
  std::string serialize();
  void setNode(BaseJsonNode *pNode);
  BaseJsonNode *getNode();
 private:
  BaseJsonNode *mNode;
};

#endif
