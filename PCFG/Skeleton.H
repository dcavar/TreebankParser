#ifndef PCFG_SKELETON_HEADER
#define PCFG_SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"

namespace pcfg
{
class Skeleton : public Visitor
{
public:
  void visitGrammar(Grammar* p);
  void visitRule(Rule* p);
  void visitLHS(LHS* p);
  void visitProb(Prob* p);
  void visitDRHS(DRHS* p);
  void visitRHS(RHS* p);
  void visitBRHS(BRHS* p);
  void visitGram(Gram* p);
  void visitRul(Rul* p);
  void visitERul(ERul* p);
  void visitLhsS(LhsS* p);
  void visitProbR(ProbR* p);
  void visitProbA(ProbA* p);
  void visitRhsDisjSyms(RhsDisjSyms* p);
  void visitRhsDisjSymsP(RhsDisjSymsP* p);
  void visitRhsDisjSymsA(RhsDisjSymsA* p);
  void visitRhsDisjTerminal(RhsDisjTerminal* p);
  void visitRhsDisj(RhsDisj* p);
  void visitRhsBrhsS(RhsBrhsS* p);
  void visitRhsBrhsSP(RhsBrhsSP* p);
  void visitRhsBrhsSA(RhsBrhsSA* p);
  void visitRhsBrhsTerminal(RhsBrhsTerminal* p);
  void visitRhsSymbol(RhsSymbol* p);
  void visitRhsSymbolP(RhsSymbolP* p);
  void visitRhsSymbolA(RhsSymbolA* p);
  void visitRhsTerminal(RhsTerminal* p);
  void visitRhsEpsilon(RhsEpsilon* p);
  void visitRhsBr(RhsBr* p);
  void visitRhsBrPlus(RhsBrPlus* p);
  void visitRhsBrAst(RhsBrAst* p);
  void visitListRule(ListRule* p);
  void visitListRHS(ListRHS* p);
  void visitListBRHS(ListBRHS* p);
  void visitListDRHS(ListDRHS* p);

  void visit"Integer"("Integer" x);
  void visit"Char"("Char" x);
  void visit"Double"("Double" x);
  void visit"String"("String" x);
  void visit"Ident"("Ident" x);

};
}

#endif
