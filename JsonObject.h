#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include <vector>
#include "JsonString.h"
#include "BaseJsonList.h"
#include "JsonObjEntry.h"

class JsonObject: public BaseJsonList{
 public:
  JsonObject(BaseJsonNode *pNode);
  ~JsonObject();
  JsonNodeType getType();
  std::string serialize();
  unsigned int count();
  BaseJsonNode *getIndex(unsigned int pIndex);
  JsonString *getKey(unsigned int pIndex);
  BaseJsonNode *get(std::string &pKey);
  void addEntry(JsonObjEntry *pEntry);
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  std::vector<JsonObjEntry*> mList;    
};

#endif
