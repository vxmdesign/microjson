#include "BaseJsonNode.h"

bool BaseJsonNode::equals(BaseJsonNode *pNode){
  if(getType() != pNode->getType()){
    return false;
  }
  return nodeEqual(pNode);
}
