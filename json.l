%{
#include "JsonParser.hpp"
#include <string.h>
#include <string>
#include "JsonScanner.h"
#undef YY_DECL
#define YY_DECL int JSON::JsonScanner::yylex(JSON::JsonParser::semantic_type * const lval, JSON::JsonParser::location_type *loc)



#define YY_NO_UNISTD_H

#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}
%option debug
%option yyclass="JSON::JsonScanner"
%option noyywrap
%option c++


EXP ([Ee][-+]?[0-9]+)

%%
%{
     yylval = lval;
%}
"{" { return JSON::JsonParser::token::LCURLY; }
"}" { return JSON::JsonParser::token::RCURLY; } 
"[" { return JSON::JsonParser::token::LBRAC; } 
"]" { return JSON::JsonParser::token::RBRAC; } 
"," { return JSON::JsonParser::token::COMMA; } 
":" { return JSON::JsonParser::token::COLON; } 
"true" { return JSON::JsonParser::token::VTRUE; } 
"false" { return JSON::JsonParser::token::VFALSE; } 
"null" { return JSON::JsonParser::token::VNULL; } 
[ \t\r\n]+ { } 
\"[^"]*\" {  yylval->build<std::string>(yytext); return JSON::JsonParser::token::STRING; } 
[0-9]+ { yylval->build<int>(atoi(yytext)); return JSON::JsonParser::token::INTEGER; } 
[0-9]+\.?[0-9]*{EXP}? { yylval->build<double>(atof(yytext)); return JSON::JsonParser::token::DECIMAL ; } 

%%

