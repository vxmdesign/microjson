#ifndef JSON_ROOT_H
#define JSON_ROOT_H

#include "BaseJsonNode.h"

class JsonRoot: public BaseJsonNode{
 public:
  JsonRoot();
  ~JsonRoot();
  JsonNodeType getType();
  std::string serialize();
  void setNode(BaseJsonNode *pNode);
  BaseJsonNode *getNode();
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  BaseJsonNode *mNode;
};

#endif
