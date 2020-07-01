#ifndef BASE_JSON_NODE_H
#define BASE_JSON_NODE_H

#include <string>

enum JsonNodeType { JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY, JSON_BOOL, JSON_NULL, JSON_ROOT};

class BaseJsonNode{
 public:
  virtual ~BaseJsonNode(){}
  virtual JsonNodeType getType() = 0;
  virtual std::string serialize() = 0;
  bool equals(BaseJsonNode *pNode);
 private:
  virtual bool nodeEqual(BaseJsonNode *pNode)=0;
};

#endif
