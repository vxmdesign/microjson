#ifndef JSON_OBJ_ENTRY_H
#define JSON_OBJ_ENTRY_H

#include "BaseJsonNode.h"
#include "JsonString.h"

class JsonObjEntry{
 public:
  JsonObjEntry(JsonString *pKey, BaseJsonNode *pValue);
  JsonString *getKey();
  BaseJsonNode *getValue();
  std::string serialize();
 private:
  JsonString *mKey;
  BaseJsonNode *mValue;
};

#endif
