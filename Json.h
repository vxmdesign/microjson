#ifndef JSON_H
#define JSON_H

#include "JsonRoot.h"
#include "JsonArray.h"
#include "JsonObject.h"
#include "JsonString.h"
#include "JsonNumber.h"
#include "JsonBool.h"
#include "JsonNull.h"
#include "JsonDriver.h"

#define CHECK_ASSIGN_TYPE(dst,src,type)    (((((dst)=((src)->getType()==type)?dynamic_cast<typeof(dst)>(src):NULL))==NULL)?-1:0)
#define CHECK_ASSIGN_SRCNULL(dst, src,type) ((src==NULL)?-1:CHECK_ASSIGN_TYPE(dst,src,type))
#define CHECK_ASSIGN_OBJECT(dst, src)       CHECK_ASSIGN_SRCNULL(dst,src, JSON_OBJECT)
#define CHECK_ASSIGN_ARRAY(dst, src)        CHECK_ASSIGN_SRCNULL(dst,src, JSON_ARRAY)                    
#define CHECK_ASSIGN_NUMBER(dst, src)       CHECK_ASSIGN_SRCNULL(dst,src, JSON_NUMBER)
#define CHECK_ASSIGN_STRING(dst, src)       CHECK_ASSIGN_SRCNULL(dst,src, JSON_STRING)
#define CHECK_ASSIGN_NULL(dst, src)        CHECK_ASSIGN_SRCNULL(dst,src, JSON_NULL)
#define CHECK_ASSIGN_BOOL(dst, src)        CHECK_ASSIGN_SRCNULL(dst,src, JSON_BOOL)


#endif

