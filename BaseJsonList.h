#ifndef BASE_JSON_LIST_H
#define BASE_JSON_LIST_H

#include <vector>
#include "BaseJsonNode.h"

class BaseJsonList: public BaseJsonNode{
 public:
  BaseJsonList(BaseJsonNode *pParent);
  BaseJsonNode *getParent();
 private:  
  BaseJsonNode *mParent;
};
#endif
