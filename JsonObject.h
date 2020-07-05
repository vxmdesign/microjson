#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include <vector>
#include "JsonString.h"
#include "BaseJsonList.h"
#include "JsonObjEntry.h"
#include "JsonBool.h"
#include "JsonString.h"
#include "JsonNumber.h"
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
  void addEntry(std::string &pKey, std::string &pValue);
  void addEntry(std::string &pKey, double pValue);
  void addEntry(std::string &pKey, bool pValue);
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  std::vector<JsonObjEntry*> mList;    
};

#endif
