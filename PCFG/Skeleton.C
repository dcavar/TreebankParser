/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"


namespace pcfg
{
void Skeleton::visitGrammar(Grammar* t) {} //abstract class
void Skeleton::visitRule(Rule* t) {} //abstract class
void Skeleton::visitLHS(LHS* t) {} //abstract class
void Skeleton::visitProb(Prob* t) {} //abstract class
void Skeleton::visitDRHS(DRHS* t) {} //abstract class
void Skeleton::visitRHS(RHS* t) {} //abstract class
void Skeleton::visitBRHS(BRHS* t) {} //abstract class

void Skeleton::visitGram(Gram *gram)
{
  /* Code For Gram Goes Here */

  gram->listrule_->accept(this);

}

void Skeleton::visitRul(Rul *rul)
{
  /* Code For Rul Goes Here */

  rul->prob_->accept(this);
  rul->lhs_->accept(this);
  rul->listrhs_->accept(this);

}

void Skeleton::visitERul(ERul *erul)
{
  /* Code For ERul Goes Here */


}

void Skeleton::visitLhsS(LhsS *lhss)
{
  /* Code For LhsS Goes Here */

  visitIdent(lhss->ident_);

}

void Skeleton::visitProbR(ProbR *probr)
{
  /* Code For ProbR Goes Here */

  visitDouble(probr->double_);

}

void Skeleton::visitProbA(ProbA *proba)
{
  /* Code For ProbA Goes Here */

  visitInteger(proba->integer_);

}

void Skeleton::visitRhsDisjSyms(RhsDisjSyms *rhsdisjsyms)
{
  /* Code For RhsDisjSyms Goes Here */

  visitIdent(rhsdisjsyms->ident_);

}

void Skeleton::visitRhsDisjSymsP(RhsDisjSymsP *rhsdisjsymsp)
{
  /* Code For RhsDisjSymsP Goes Here */

  visitIdent(rhsdisjsymsp->ident_);

}

void Skeleton::visitRhsDisjSymsA(RhsDisjSymsA *rhsdisjsymsa)
{
  /* Code For RhsDisjSymsA Goes Here */

  visitIdent(rhsdisjsymsa->ident_);

}

void Skeleton::visitRhsDisjTerminal(RhsDisjTerminal *rhsdisjterminal)
{
  /* Code For RhsDisjTerminal Goes Here */

  visitString(rhsdisjterminal->string_);

}

void Skeleton::visitRhsDisj(RhsDisj *rhsdisj)
{
  /* Code For RhsDisj Goes Here */

  rhsdisj->listdrhs_->accept(this);

}

void Skeleton::visitRhsSymbol(RhsSymbol *rhssymbol)
{
  /* Code For RhsSymbol Goes Here */

  visitIdent(rhssymbol->ident_);

}

void Skeleton::visitRhsSymbolP(RhsSymbolP *rhssymbolp)
{
  /* Code For RhsSymbolP Goes Here */

  visitIdent(rhssymbolp->ident_);

}

void Skeleton::visitRhsSymbolA(RhsSymbolA *rhssymbola)
{
  /* Code For RhsSymbolA Goes Here */

  visitIdent(rhssymbola->ident_);

}

void Skeleton::visitRhsTerminal(RhsTerminal *rhsterminal)
{
  /* Code For RhsTerminal Goes Here */

  visitString(rhsterminal->string_);

}

void Skeleton::visitRhsEpsilon(RhsEpsilon *rhsepsilon)
{
  /* Code For RhsEpsilon Goes Here */


}

void Skeleton::visitRhsBr(RhsBr *rhsbr)
{
  /* Code For RhsBr Goes Here */

  rhsbr->listbrhs_->accept(this);

}

void Skeleton::visitRhsBrPlus(RhsBrPlus *rhsbrplus)
{
  /* Code For RhsBrPlus Goes Here */

  rhsbrplus->listbrhs_->accept(this);

}

void Skeleton::visitRhsBrAst(RhsBrAst *rhsbrast)
{
  /* Code For RhsBrAst Goes Here */

  rhsbrast->listbrhs_->accept(this);

}

void Skeleton::visitRhsBrhsS(RhsBrhsS *rhsbrhss)
{
  /* Code For RhsBrhsS Goes Here */

  visitIdent(rhsbrhss->ident_);

}

void Skeleton::visitRhsBrhsSP(RhsBrhsSP *rhsbrhssp)
{
  /* Code For RhsBrhsSP Goes Here */

  visitIdent(rhsbrhssp->ident_);

}

void Skeleton::visitRhsBrhsSA(RhsBrhsSA *rhsbrhssa)
{
  /* Code For RhsBrhsSA Goes Here */

  visitIdent(rhsbrhssa->ident_);

}

void Skeleton::visitRhsBrhsTerminal(RhsBrhsTerminal *rhsbrhsterminal)
{
  /* Code For RhsBrhsTerminal Goes Here */

  visitString(rhsbrhsterminal->string_);

}


void Skeleton::visitListRule(ListRule* listrule)
{
  for (ListRule::iterator i = listrule->begin() ; i != listrule->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListRHS(ListRHS* listrhs)
{
  for (ListRHS::iterator i = listrhs->begin() ; i != listrhs->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListBRHS(ListBRHS* listbrhs)
{
  for (ListBRHS::iterator i = listbrhs->begin() ; i != listbrhs->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListDRHS(ListDRHS* listdrhs)
{
  for (ListDRHS::iterator i = listdrhs->begin() ; i != listdrhs->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}


}
