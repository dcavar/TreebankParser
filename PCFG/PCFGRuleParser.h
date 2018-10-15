//
// Created by Damir Cavar on 3/4/16.
//

#ifndef GRAMMARTEST_PCFGRULEPARSER_H
#define GRAMMARTEST_PCFGRULEPARSER_H

#include <iostream>
#include <vector>
#include <limits.h>
#include "../FLEWFST.h"
#include "Absyn.H"
#include "Parser.H"


using namespace std;


namespace pcfg {

    class PCFGRuleParser : public Visitor {
    public:
        void visitGrammar(Grammar *p);

        void visitRule(Rule *p);

        void visitLHS(LHS *p);

        void visitProb(Prob *p);

        void visitSYM(SYM *p);

        void visitT(T *p);

        void visitRHS(RHS *p);

        void visitGram(Gram *p);

        void visitRul(Rul *p);

        void visitERul(ERul *p);

        void visitLhsS(LhsS *p);

        void visitProbS(ProbS *p);

        void visitSymb(Symb *p);

        void visitSymbPlus(SymbPlus *p);

        void visitSymbAst(SymbAst *p);

        void visitSymbOpt(SymbOpt *p);

        void visitTerm(Term *p);

        void visitTermPlus(TermPlus *p);

        void visitTermAst(TermAst *p);

        void visitTermOpt(TermOpt *p);

        void visitRhsS(RhsS *p);

        void visitRhsSR(RhsSR *p);

        void visitRhsT(RhsT *p);

        void visitRhsTR(RhsTR *p);

        void visitRhsBr(RhsBr *p);

        void visitRhsBrPlus(RhsBrPlus *p);

        void visitRhsBrAst(RhsBrAst *p);

        void visitRhsBrOpt(RhsBrOpt *p);

        void visitListRHS(ListRHS *p);

        void visitListRule(ListRule *p);

        void visitInteger(Integer x);

        void visitChar(Char x);

        void visitDouble(Double x);

        void visitString(String x);

        void visitIdent(Ident x);

        void getRules(const char *str, FLEWFST &newFST);

        bool verbose;

        unsigned long count_rules = 0;


    private:
        FLEWFST *myFST;
        /*!< the WFST for the grammar */

        unsigned long myLHS;
        /*!< ID of the left-hand-side symbol */

        vector<pair<unsigned long, unsigned int>> myRHS;
        /*!< vector of the right-hand-side symbol IDs and type */

        unsigned long lastState = 0;
        /*!< ID of the last state in myFST */

        bool optionalSymbol = false;

        bool plusBrSymbol = false;

        bool astBrSymbol = false;

    };

}

#endif //GRAMMARTEST_PCFGRULEPARSER_H
