#ifndef JSON_DRIVER_H
#define JSON_DRIVER_H

#include <string>
#include <sstream>
#include "JsonParser.hpp"
#include "JsonScanner.h"
#include "JsonRoot.h"
#include "BaseJsonList.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "JsonObjEntry.h"
namespace JSON{
  class JsonDriver{
  public:
    JsonDriver();
    virtual ~JsonDriver();
    int parse(std::string &pInput);
    void pushObject();
    void pushArray();
    int insert(JsonObjEntry *pEntry);
    int insert(BaseJsonNode *pNode);
    JsonArray* popArray();
    JsonObject* popObject();
    JsonRoot *getRoot();
  private:
    JSON::JsonParser *mParser;
    JSON::JsonScanner *mScanner;
    JsonRoot *mRoot;
    BaseJsonNode *mCurrent;
  };
}

#endif
