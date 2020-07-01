%skeleton "lalr1.cc"
%require "3.0"
%defines
%define api.namespace {JSON}
%define parser_class_name {JsonParser}
%define parse.trace
%code requires{
   #include "BaseJsonNode.h"
   #include "JsonNull.h"
   #include "JsonBool.h"
   #include "JsonString.h"
   #include "JsonNumber.h"
   #include "JsonArray.h"
   #include "JsonObject.h"
   #include "JsonObjEntry.h"
   namespace JSON{
      class JsonDriver;
      class JsonScanner;
   }
}

%parse-param { JsonScanner *scanner }
%parse-param { JsonDriver *driver } 

%code{

   #include <stdio.h>
   #include <iostream>
   #include "JsonDriver.h"
   
#undef yylex
#define yylex scanner->yylex
}

%define api.value.type variant
%define parse.assert

%token LCURLY RCURLY LBRAC RBRAC COMMA COLON
%token VTRUE VFALSE VNULL
%token <std::string> STRING;
%token <double> DECIMAL;
%type <BaseJsonNode *> value
%type <JsonObjEntry*> member
%type <JsonObject*> object
%type <JsonArray*> array

%locations

%%

json:
	| value 
	;

value: object     { $$ = $1; } 
	| array   { $$ = $1; } 
	| STRING  { $$ = new JsonString($1); }
	| DECIMAL { $$ = new JsonNumber($1); } 
	| VTRUE   { $$ = new JsonBool(true); } 
	| VFALSE  { $$ = new JsonBool(false); }
	| VNULL   { $$ = new JsonNull(); }
	;

object: LCURLY RCURLY            { driver->pushObject(); $$ = driver->popObject(); } 
	| LCURLY members RCURLY  { $$ = driver->popObject(); } 
	;

members: member                  { driver->pushObject(); driver->insert($1); }      
	| members COMMA member   { driver->insert($3); } 
	;

member: STRING COLON value 	 { $$ = new JsonObjEntry(new JsonString($1), $3); } 
	;

array: LBRAC RBRAC               { driver->pushArray(); $$ = driver->popArray(); }
	| LBRAC values RBRAC     { $$ = driver->popArray(); } 
	;

values: value                    { driver->pushArray(); driver->insert($1); }
	| values COMMA value     { driver->insert($3); } 
	;


%%

void JSON::JsonParser::error(const location_type &l, const std::string &err_message){
   std::cerr << "Error: " << err_message << " at " << l << "\n";
   
}
