#ifndef JSON_SCANNER_H
#define JSON_SCANNER_H

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "JsonParser.hpp"
#include "location.hh"

namespace JSON{
  class JsonScanner: public yyFlexLexer{
  public:
    JsonScanner(std::istream *in): yyFlexLexer(in){}
    virtual ~JsonScanner(){}
    using FlexLexer::yylex;
    int yylex(JSON::JsonParser::semantic_type *const lval, JSON::JsonParser::location_type *location);
  private:
    JSON::JsonParser::semantic_type *yylval = NULL;
  };
}

#endif
