#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H



#include <vector>
#include "BaseJsonList.h"

class JsonArray: public BaseJsonList{
 public:
  JsonArray(BaseJsonNode *pParent);
  ~JsonArray();
  JsonNodeType getType();
  std::string serialize();
  unsigned int count();
  BaseJsonNode *get(unsigned int pIndex);
  void addEntry(BaseJsonNode *pNode);
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  std::vector<BaseJsonNode*> mList;
};

#endif
