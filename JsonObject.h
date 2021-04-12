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
  BaseJsonNode *get(const char *pKey);
  void addEntry(JsonObjEntry *pEntry);
  void addEntry(const char *pKey, std::string &pValue);
  void addEntry(const char *pKey, const char *pValue);
  void addEntry(const char *pKey, double pValue);
  void addEntry(const char *pKey, bool pValue);
  void addEntry(const char *pKey, int pValue);
 private:
  bool nodeEqual(BaseJsonNode *pNode);
  std::vector<JsonObjEntry*> mList;    
};

#endif
