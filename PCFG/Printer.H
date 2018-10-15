#ifndef PCFG_PRINTER_HEADER
#define PCFG_PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace pcfg
{
/* Certain applications may improve performance by changing the buffer size */
#define PCFG_BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define PCFG__L_PAREN '('
#define PCFG__R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
void render(char* s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitGrammar(Grammar *p); /* abstract class */
  void visitGram(Gram *p);
  void visitRule(Rule *p); /* abstract class */
  void visitRul(Rul *p);
  void visitERul(ERul *p);
  void visitListRule(ListRule* p);
  void visitLHS(LHS *p); /* abstract class */
  void visitLhsS(LhsS *p);
  void visitProb(Prob *p); /* abstract class */
  void visitProbR(ProbR *p);
  void visitProbA(ProbA *p);
  void visitDRHS(DRHS *p); /* abstract class */
  void visitRhsDisjSyms(RhsDisjSyms *p);
  void visitRhsDisjSymsP(RhsDisjSymsP *p);
  void visitRhsDisjSymsA(RhsDisjSymsA *p);
  void visitRhsDisjTerminal(RhsDisjTerminal *p);
  void visitRHS(RHS *p); /* abstract class */
  void visitRhsDisj(RhsDisj *p);
  void visitRhsSymbol(RhsSymbol *p);
  void visitRhsSymbolP(RhsSymbolP *p);
  void visitRhsSymbolA(RhsSymbolA *p);
  void visitRhsTerminal(RhsTerminal *p);
  void visitRhsEpsilon(RhsEpsilon *p);
  void visitRhsBr(RhsBr *p);
  void visitRhsBrPlus(RhsBrPlus *p);
  void visitRhsBrAst(RhsBrAst *p);
  void visitBRHS(BRHS *p); /* abstract class */
  void visitRhsBrhsS(RhsBrhsS *p);
  void visitRhsBrhsSP(RhsBrhsSP *p);
  void visitRhsBrhsSA(RhsBrhsSA *p);
  void visitRhsBrhsTerminal(RhsBrhsTerminal *p);
  void visitListRHS(ListRHS* p);
  void visitListBRHS(ListBRHS* p);
  void visitListDRHS(ListDRHS* p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = PCFG_BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitGrammar(Grammar *p); /* abstract class */
  void visitGram(Gram *p);
  void visitRule(Rule *p); /* abstract class */
  void visitRul(Rul *p);
  void visitERul(ERul *p);
  void visitListRule(ListRule* p);
  void visitLHS(LHS *p); /* abstract class */
  void visitLhsS(LhsS *p);
  void visitProb(Prob *p); /* abstract class */
  void visitProbR(ProbR *p);
  void visitProbA(ProbA *p);
  void visitDRHS(DRHS *p); /* abstract class */
  void visitRhsDisjSyms(RhsDisjSyms *p);
  void visitRhsDisjSymsP(RhsDisjSymsP *p);
  void visitRhsDisjSymsA(RhsDisjSymsA *p);
  void visitRhsDisjTerminal(RhsDisjTerminal *p);
  void visitRHS(RHS *p); /* abstract class */
  void visitRhsDisj(RhsDisj *p);
  void visitRhsSymbol(RhsSymbol *p);
  void visitRhsSymbolP(RhsSymbolP *p);
  void visitRhsSymbolA(RhsSymbolA *p);
  void visitRhsTerminal(RhsTerminal *p);
  void visitRhsEpsilon(RhsEpsilon *p);
  void visitRhsBr(RhsBr *p);
  void visitRhsBrPlus(RhsBrPlus *p);
  void visitRhsBrAst(RhsBrAst *p);
  void visitBRHS(BRHS *p); /* abstract class */
  void visitRhsBrhsS(RhsBrhsS *p);
  void visitRhsBrhsSP(RhsBrhsSP *p);
  void visitRhsBrhsSA(RhsBrhsSA *p);
  void visitRhsBrhsTerminal(RhsBrhsTerminal *p);
  void visitListRHS(ListRHS* p);
  void visitListBRHS(ListBRHS* p);
  void visitListDRHS(ListDRHS* p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = PCFG_BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};


}

#endif

