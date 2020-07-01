#include "BaseJsonList.h"

BaseJsonList::BaseJsonList(BaseJsonNode *pParent){
  mParent = pParent;
}

BaseJsonNode* BaseJsonList::getParent(){
  return mParent;
}

