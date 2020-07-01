// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "JsonParser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "JsonParser.hpp"

// User implementation prologue.

#line 51 "JsonParser.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 25 "json.yy" // lalr1.cc:413


   #include <stdio.h>
   #include <iostream>
   #include "JsonDriver.h"
   
#undef yylex
#define yylex scanner->yylex

#line 63 "JsonParser.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "json.yy" // lalr1.cc:479
namespace JSON {
#line 149 "JsonParser.cpp" // lalr1.cc:479

  /// Build a parser object.
  JsonParser::JsonParser (JsonScanner *scanner_yyarg, JsonDriver *driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  JsonParser::~JsonParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  JsonParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  JsonParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  JsonParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 16: // value
        value.copy< BaseJsonNode * > (other.value);
        break;

      case 20: // array
        value.copy< JsonArray* > (other.value);
        break;

      case 19: // member
        value.copy< JsonObjEntry* > (other.value);
        break;

      case 17: // object
        value.copy< JsonObject* > (other.value);
        break;

      case 13: // DECIMAL
        value.copy< double > (other.value);
        break;

      case 12: // STRING
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 16: // value
        value.copy< BaseJsonNode * > (v);
        break;

      case 20: // array
        value.copy< JsonArray* > (v);
        break;

      case 19: // member
        value.copy< JsonObjEntry* > (v);
        break;

      case 17: // object
        value.copy< JsonObject* > (v);
        break;

      case 13: // DECIMAL
        value.copy< double > (v);
        break;

      case 12: // STRING
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const BaseJsonNode * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const JsonArray* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const JsonObjEntry* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const JsonObject* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const double v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  JsonParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  JsonParser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 16: // value
        value.template destroy< BaseJsonNode * > ();
        break;

      case 20: // array
        value.template destroy< JsonArray* > ();
        break;

      case 19: // member
        value.template destroy< JsonObjEntry* > ();
        break;

      case 17: // object
        value.template destroy< JsonObject* > ();
        break;

      case 13: // DECIMAL
        value.template destroy< double > ();
        break;

      case 12: // STRING
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  JsonParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  JsonParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 16: // value
        value.move< BaseJsonNode * > (s.value);
        break;

      case 20: // array
        value.move< JsonArray* > (s.value);
        break;

      case 19: // member
        value.move< JsonObjEntry* > (s.value);
        break;

      case 17: // object
        value.move< JsonObject* > (s.value);
        break;

      case 13: // DECIMAL
        value.move< double > (s.value);
        break;

      case 12: // STRING
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  JsonParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  JsonParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  JsonParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  JsonParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  JsonParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  JsonParser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  JsonParser::symbol_type
  JsonParser::make_LCURLY (const location_type& l)
  {
    return symbol_type (token::LCURLY, l);
  }

  JsonParser::symbol_type
  JsonParser::make_RCURLY (const location_type& l)
  {
    return symbol_type (token::RCURLY, l);
  }

  JsonParser::symbol_type
  JsonParser::make_LBRAC (const location_type& l)
  {
    return symbol_type (token::LBRAC, l);
  }

  JsonParser::symbol_type
  JsonParser::make_RBRAC (const location_type& l)
  {
    return symbol_type (token::RBRAC, l);
  }

  JsonParser::symbol_type
  JsonParser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);
  }

  JsonParser::symbol_type
  JsonParser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);
  }

  JsonParser::symbol_type
  JsonParser::make_VTRUE (const location_type& l)
  {
    return symbol_type (token::VTRUE, l);
  }

  JsonParser::symbol_type
  JsonParser::make_VFALSE (const location_type& l)
  {
    return symbol_type (token::VFALSE, l);
  }

  JsonParser::symbol_type
  JsonParser::make_VNULL (const location_type& l)
  {
    return symbol_type (token::VNULL, l);
  }

  JsonParser::symbol_type
  JsonParser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING, v, l);
  }

  JsonParser::symbol_type
  JsonParser::make_DECIMAL (const double& v, const location_type& l)
  {
    return symbol_type (token::DECIMAL, v, l);
  }



  // by_state.
  inline
  JsonParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  JsonParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  JsonParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  JsonParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  JsonParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  JsonParser::symbol_number_type
  JsonParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  JsonParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  JsonParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 16: // value
        value.move< BaseJsonNode * > (that.value);
        break;

      case 20: // array
        value.move< JsonArray* > (that.value);
        break;

      case 19: // member
        value.move< JsonObjEntry* > (that.value);
        break;

      case 17: // object
        value.move< JsonObject* > (that.value);
        break;

      case 13: // DECIMAL
        value.move< double > (that.value);
        break;

      case 12: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  JsonParser::stack_symbol_type&
  JsonParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 16: // value
        value.copy< BaseJsonNode * > (that.value);
        break;

      case 20: // array
        value.copy< JsonArray* > (that.value);
        break;

      case 19: // member
        value.copy< JsonObjEntry* > (that.value);
        break;

      case 17: // object
        value.copy< JsonObject* > (that.value);
        break;

      case 13: // DECIMAL
        value.copy< double > (that.value);
        break;

      case 12: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  JsonParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  JsonParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  JsonParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  JsonParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  JsonParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  JsonParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  JsonParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  JsonParser::debug_level_type
  JsonParser::debug_level () const
  {
    return yydebug_;
  }

  void
  JsonParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline JsonParser::state_type
  JsonParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  JsonParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  JsonParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  JsonParser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 16: // value
        yylhs.value.build< BaseJsonNode * > ();
        break;

      case 20: // array
        yylhs.value.build< JsonArray* > ();
        break;

      case 19: // member
        yylhs.value.build< JsonObjEntry* > ();
        break;

      case 17: // object
        yylhs.value.build< JsonObject* > ();
        break;

      case 13: // DECIMAL
        yylhs.value.build< double > ();
        break;

      case 12: // STRING
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 4:
#line 55 "json.yy" // lalr1.cc:859
    { yylhs.value.as< BaseJsonNode * > () = yystack_[0].value.as< JsonObject* > (); }
#line 910 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 56 "json.yy" // lalr1.cc:859
    { yylhs.value.as< BaseJsonNode * > () = yystack_[0].value.as< JsonArray* > (); }
#line 916 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 57 "json.yy" // lalr1.cc:859
    { yylhs.value.as< BaseJsonNode * > () = new JsonString(yystack_[0].value.as< std::string > ()); }
#line 922 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 58 "json.yy" // lalr1.cc:859
    { yylhs.value.as< BaseJsonNode * > () = new JsonNumber(yystack_[0].value.as< double > ()); }
#line 928 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 59 "json.yy" // lalr1.cc:859
    { yylhs.value.as< BaseJsonNode * > () = new JsonBool(true); }
#line 934 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 60 "json.yy" // lalr1.cc:859
    { yylhs.value.as< BaseJsonNode * > () = new JsonBool(false); }
#line 940 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 61 "json.yy" // lalr1.cc:859
    { yylhs.value.as< BaseJsonNode * > () = new JsonNull(); }
#line 946 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 64 "json.yy" // lalr1.cc:859
    { driver->pushObject(); yylhs.value.as< JsonObject* > () = driver->popObject(); }
#line 952 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 65 "json.yy" // lalr1.cc:859
    { yylhs.value.as< JsonObject* > () = driver->popObject(); }
#line 958 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 68 "json.yy" // lalr1.cc:859
    { driver->pushObject(); driver->insert(yystack_[0].value.as< JsonObjEntry* > ()); }
#line 964 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 69 "json.yy" // lalr1.cc:859
    { driver->insert(yystack_[0].value.as< JsonObjEntry* > ()); }
#line 970 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 72 "json.yy" // lalr1.cc:859
    { yylhs.value.as< JsonObjEntry* > () = new JsonObjEntry(new JsonString(yystack_[2].value.as< std::string > ()), yystack_[0].value.as< BaseJsonNode * > ()); }
#line 976 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 75 "json.yy" // lalr1.cc:859
    { driver->pushArray(); yylhs.value.as< JsonArray* > () = driver->popArray(); }
#line 982 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 76 "json.yy" // lalr1.cc:859
    { yylhs.value.as< JsonArray* > () = driver->popArray(); }
#line 988 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 79 "json.yy" // lalr1.cc:859
    { driver->pushArray(); driver->insert(yystack_[0].value.as< BaseJsonNode * > ()); }
#line 994 "JsonParser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 80 "json.yy" // lalr1.cc:859
    { driver->insert(yystack_[0].value.as< BaseJsonNode * > ()); }
#line 1000 "JsonParser.cpp" // lalr1.cc:859
    break;


#line 1004 "JsonParser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  JsonParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  JsonParser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char JsonParser::yypact_ninf_ = -16;

  const signed char JsonParser::yytable_ninf_ = -1;

  const signed char
  JsonParser::yypact_[] =
  {
      14,     2,    -1,   -16,   -16,   -16,   -16,   -16,     1,   -16,
     -16,   -16,   -16,    -5,     9,   -16,   -16,   -16,    22,   -16,
      14,   -16,     3,   -16,    14,   -16,   -16,   -16
  };

  const unsigned char
  JsonParser::yydefact_[] =
  {
       2,     0,     0,     8,     9,    10,     6,     7,     0,     3,
       4,     5,    11,     0,     0,    13,    16,    18,     0,     1,
       0,    12,     0,    17,     0,    15,    14,    19
  };

  const signed char
  JsonParser::yypgoto_[] =
  {
     -16,   -16,    -2,   -16,   -16,   -15,   -16,   -16
  };

  const signed char
  JsonParser::yydefgoto_[] =
  {
      -1,     8,     9,    10,    14,    15,    11,    18
  };

  const unsigned char
  JsonParser::yytable_[] =
  {
      17,    19,     1,    20,     2,    16,    12,    26,     3,     4,
       5,     6,     7,    21,    13,    13,    22,     1,    25,     2,
       0,     0,    27,     3,     4,     5,     6,     7,    23,    24
  };

  const signed char
  JsonParser::yycheck_[] =
  {
       2,     0,     3,     8,     5,     6,     4,    22,     9,    10,
      11,    12,    13,     4,    12,    12,     7,     3,    20,     5,
      -1,    -1,    24,     9,    10,    11,    12,    13,     6,     7
  };

  const unsigned char
  JsonParser::yystos_[] =
  {
       0,     3,     5,     9,    10,    11,    12,    13,    15,    16,
      17,    20,     4,    12,    18,    19,     6,    16,    21,     0,
       8,     4,     7,     6,     7,    16,    19,    16
  };

  const unsigned char
  JsonParser::yyr1_[] =
  {
       0,    14,    15,    15,    16,    16,    16,    16,    16,    16,
      16,    17,    17,    18,    18,    19,    20,    20,    21,    21
  };

  const unsigned char
  JsonParser::yyr2_[] =
  {
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     3,     3,     2,     3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const JsonParser::yytname_[] =
  {
  "$end", "error", "$undefined", "LCURLY", "RCURLY", "LBRAC", "RBRAC",
  "COMMA", "COLON", "VTRUE", "VFALSE", "VNULL", "STRING", "DECIMAL",
  "$accept", "json", "value", "object", "members", "member", "array",
  "values", YY_NULLPTR
  };


  const unsigned char
  JsonParser::yyrline_[] =
  {
       0,    51,    51,    52,    55,    56,    57,    58,    59,    60,
      61,    64,    65,    68,    69,    72,    75,    76,    79,    80
  };

  // Print the state stack on the debug stream.
  void
  JsonParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  JsonParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  JsonParser::token_number_type
  JsonParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
    };
    const unsigned int user_token_number_max_ = 268;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 4 "json.yy" // lalr1.cc:1167
} // JSON
#line 1340 "JsonParser.cpp" // lalr1.cc:1167
#line 84 "json.yy" // lalr1.cc:1168


void JSON::JsonParser::error(const location_type &l, const std::string &err_message){
   std::cerr << "Error: " << err_message << " at " << l << "\n";
   
}
