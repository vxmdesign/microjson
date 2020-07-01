#include "JsonNull.h"

JsonNull::JsonNull(){}

JsonNodeType JsonNull::getType(){
  return JSON_NULL;
}

std::string JsonNull::serialize(){
  return std::string("null");
}

				
