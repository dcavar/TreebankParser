/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"
#define INDENT_WIDTH 2

namespace pcfg
{
//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for (t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(' ');
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::render(char* s)
{
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitGrammar(Grammar*p) {} //abstract class

void PrintAbsyn::visitGram(Gram* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  if(p->listrule_) {_i_ = 0; p->listrule_->accept(this);}
  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRule(Rule*p) {} //abstract class

void PrintAbsyn::visitRul(Rul* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  _i_ = 0; p->prob_->accept(this);
  _i_ = 0; p->lhs_->accept(this);
  render("-->");
  if(p->listrhs_) {_i_ = 0; p->listrhs_->accept(this);}
  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERul(ERul* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);


  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListRule(ListRule *listrule)
{
  for (ListRule::const_iterator i = listrule->begin() ; i != listrule->end() ; ++i)
  {
    (*i)->accept(this);
    render("\\n");
  }
}void PrintAbsyn::visitLHS(LHS*p) {} //abstract class

void PrintAbsyn::visitLhsS(LhsS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitProb(Prob*p) {} //abstract class

void PrintAbsyn::visitProbR(ProbR* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitDouble(p->double_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitProbA(ProbA* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDRHS(DRHS*p) {} //abstract class

void PrintAbsyn::visitRhsDisjSyms(RhsDisjSyms* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsDisjSymsP(RhsDisjSymsP* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);
  render('+');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsDisjSymsA(RhsDisjSymsA* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);
  render('*');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsDisjTerminal(RhsDisjTerminal* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRHS(RHS*p) {} //abstract class

void PrintAbsyn::visitRhsDisj(RhsDisj* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  render('{');
  if(p->listdrhs_) {_i_ = 0; p->listdrhs_->accept(this);}  render('}');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsSymbol(RhsSymbol* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsSymbolP(RhsSymbolP* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);
  render('+');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsSymbolA(RhsSymbolA* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);
  render('*');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsTerminal(RhsTerminal* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsEpsilon(RhsEpsilon* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  render('e');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsBr(RhsBr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  render('(');
  if(p->listbrhs_) {_i_ = 0; p->listbrhs_->accept(this);}  render(')');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsBrPlus(RhsBrPlus* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  render('(');
  if(p->listbrhs_) {_i_ = 0; p->listbrhs_->accept(this);}  render(')');
  render('+');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsBrAst(RhsBrAst* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  render('(');
  if(p->listbrhs_) {_i_ = 0; p->listbrhs_->accept(this);}  render(')');
  render('*');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBRHS(BRHS*p) {} //abstract class

void PrintAbsyn::visitRhsBrhsS(RhsBrhsS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsBrhsSP(RhsBrhsSP* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);
  render('+');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsBrhsSA(RhsBrhsSA* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitIdent(p->ident_);
  render('*');

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRhsBrhsTerminal(RhsBrhsTerminal* p)
{
  int oldi = _i_;
  if (oldi > 0) render(PCFG__L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(PCFG__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListRHS(ListRHS *listrhs)
{
  for (ListRHS::const_iterator i = listrhs->begin() ; i != listrhs->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}void PrintAbsyn::visitListBRHS(ListBRHS *listbrhs)
{
  for (ListBRHS::const_iterator i = listbrhs->begin() ; i != listbrhs->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}void PrintAbsyn::visitListDRHS(ListDRHS *listdrhs)
{
  for (ListDRHS::const_iterator i = listdrhs->begin() ; i != listdrhs->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdrhs->end() - 1) render('|');
  }
}void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s)
{
  render(s);
}

ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitGrammar(Grammar* p) {} //abstract class

void ShowAbsyn::visitGram(Gram* p)
{
  bufAppend('(');
  bufAppend("Gram");
  bufAppend(' ');
  bufAppend('[');
  if (p->listrule_)  p->listrule_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitRule(Rule* p) {} //abstract class

void ShowAbsyn::visitRul(Rul* p)
{
  bufAppend('(');
  bufAppend("Rul");
  bufAppend(' ');
  bufAppend('[');
  if (p->prob_)  p->prob_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->lhs_)  p->lhs_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listrhs_)  p->listrhs_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitERul(ERul* p)
{
  bufAppend("ERul");
}
void ShowAbsyn::visitListRule(ListRule *listrule)
{
  for (ListRule::const_iterator i = listrule->begin() ; i != listrule->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listrule->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitLHS(LHS* p) {} //abstract class

void ShowAbsyn::visitLhsS(LhsS* p)
{
  bufAppend('(');
  bufAppend("LhsS");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitProb(Prob* p) {} //abstract class

void ShowAbsyn::visitProbR(ProbR* p)
{
  bufAppend('(');
  bufAppend("ProbR");
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitProbA(ProbA* p)
{
  bufAppend('(');
  bufAppend("ProbA");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitDRHS(DRHS* p) {} //abstract class

void ShowAbsyn::visitRhsDisjSyms(RhsDisjSyms* p)
{
  bufAppend('(');
  bufAppend("RhsDisjSyms");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitRhsDisjSymsP(RhsDisjSymsP* p)
{
  bufAppend('(');
  bufAppend("RhsDisjSymsP");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsDisjSymsA(RhsDisjSymsA* p)
{
  bufAppend('(');
  bufAppend("RhsDisjSymsA");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsDisjTerminal(RhsDisjTerminal* p)
{
  bufAppend('(');
  bufAppend("RhsDisjTerminal");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitRHS(RHS* p) {} //abstract class

void ShowAbsyn::visitRhsDisj(RhsDisj* p)
{
  bufAppend('(');
  bufAppend("RhsDisj");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdrhs_)  p->listdrhs_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsSymbol(RhsSymbol* p)
{
  bufAppend('(');
  bufAppend("RhsSymbol");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitRhsSymbolP(RhsSymbolP* p)
{
  bufAppend('(');
  bufAppend("RhsSymbolP");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsSymbolA(RhsSymbolA* p)
{
  bufAppend('(');
  bufAppend("RhsSymbolA");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsTerminal(RhsTerminal* p)
{
  bufAppend('(');
  bufAppend("RhsTerminal");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitRhsEpsilon(RhsEpsilon* p)
{
  bufAppend("RhsEpsilon");
}
void ShowAbsyn::visitRhsBr(RhsBr* p)
{
  bufAppend('(');
  bufAppend("RhsBr");
  bufAppend(' ');
  bufAppend('[');
  if (p->listbrhs_)  p->listbrhs_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsBrPlus(RhsBrPlus* p)
{
  bufAppend('(');
  bufAppend("RhsBrPlus");
  bufAppend(' ');
  bufAppend('[');
  if (p->listbrhs_)  p->listbrhs_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsBrAst(RhsBrAst* p)
{
  bufAppend('(');
  bufAppend("RhsBrAst");
  bufAppend(' ');
  bufAppend('[');
  if (p->listbrhs_)  p->listbrhs_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitBRHS(BRHS* p) {} //abstract class

void ShowAbsyn::visitRhsBrhsS(RhsBrhsS* p)
{
  bufAppend('(');
  bufAppend("RhsBrhsS");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitRhsBrhsSP(RhsBrhsSP* p)
{
  bufAppend('(');
  bufAppend("RhsBrhsSP");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsBrhsSA(RhsBrhsSA* p)
{
  bufAppend('(');
  bufAppend("RhsBrhsSA");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitRhsBrhsTerminal(RhsBrhsTerminal* p)
{
  bufAppend('(');
  bufAppend("RhsBrhsTerminal");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitListRHS(ListRHS *listrhs)
{
  for (ListRHS::const_iterator i = listrhs->begin() ; i != listrhs->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listrhs->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListBRHS(ListBRHS *listbrhs)
{
  for (ListBRHS::const_iterator i = listbrhs->begin() ; i != listbrhs->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listbrhs->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListDRHS(ListDRHS *listdrhs)
{
  for (ListDRHS::const_iterator i = listdrhs->begin() ; i != listdrhs->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdrhs->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}

}
