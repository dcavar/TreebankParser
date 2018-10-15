#ifndef PCFG_PARSER_HEADER_FILE
#define PCFG_PARSER_HEADER_FILE

#include<vector>
#include<string>

namespace pcfg
{
class Grammar;
class Rule;
class ListRule;
class LHS;
class Prob;
class DRHS;
class RHS;
class BRHS;
class ListRHS;
class ListBRHS;
class ListDRHS;

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Grammar* grammar_;
  Rule* rule_;
  ListRule* listrule_;
  LHS* lhs_;
  Prob* prob_;
  DRHS* drhs_;
  RHS* rhs_;
  BRHS* brhs_;
  ListRHS* listrhs_;
  ListBRHS* listbrhs_;
  ListDRHS* listdrhs_;
} YYSTYPE;

Grammar* pGrammar(FILE *inp);
Grammar* pGrammar(const char *str);
Rule* pRule(FILE *inp);
Rule* pRule(const char *str);
ListRule* pListRule(FILE *inp);
ListRule* pListRule(const char *str);
LHS* pLHS(FILE *inp);
LHS* pLHS(const char *str);
Prob* pProb(FILE *inp);
Prob* pProb(const char *str);
DRHS* pDRHS(FILE *inp);
DRHS* pDRHS(const char *str);
RHS* pRHS(FILE *inp);
RHS* pRHS(const char *str);
BRHS* pBRHS(FILE *inp);
BRHS* pBRHS(const char *str);
ListRHS* pListRHS(FILE *inp);
ListRHS* pListRHS(const char *str);
ListBRHS* pListBRHS(FILE *inp);
ListBRHS* pListBRHS(const char *str);
ListDRHS* pListDRHS(FILE *inp);
ListDRHS* pListDRHS(const char *str);

}

#define PCFG__ERROR_ 258
#define PCFG__SYMB_0 259
#define PCFG__SYMB_1 260
#define PCFG__SYMB_2 261
#define PCFG__SYMB_3 262
#define PCFG__SYMB_4 263
#define PCFG__SYMB_5 264
#define PCFG__SYMB_6 265
#define PCFG__SYMB_7 266
#define PCFG__SYMB_8 267
#define PCFG__SYMB_9 268
#define PCFG__STRING_ 269
#define PCFG__INTEGER_ 270
#define PCFG__DOUBLE_ 271
#define PCFG__IDENT_ 272

extern pcfg::YYSTYPE pcfgyylval;

#endif
