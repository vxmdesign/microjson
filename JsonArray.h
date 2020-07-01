#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H



#include <vector>
#include "BaseJsonList.h"

class JsonArray: public BaseJsonList{
 public:
  JsonArray(BaseJsonNode *pParent);
  JsonNodeType getType();
  std::string serialize();
  unsigned int count();
  BaseJsonNode *getIndex(unsigned int pIndex);
  void addNode(BaseJsonNode *pNode);
 private:
  std::vector<BaseJsonNode*> mList;
};

#endif
