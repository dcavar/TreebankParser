//
// Created by Damir Cavar on 3/4/16.
//

#include "PCFGRuleParser.h"

namespace pcfg {

    void PCFGRuleParser::getRules(const char *str, FLEWFST &newFST) {
        if (verbose)
            cout << "Parsing rule." << endl;
        myFST = &newFST;
        myLHS = myFST->FLEEPSILON; /*!< ID of the last state in myFST */
        lastState = myFST->start_state;
        //lastTransition = make_pair(make_pair((unsigned long)0, (unsigned long)0), make_tuple((unsigned long)0, (unsigned long)0, (double)0.0));

        // change the returned type or the way it is constructed!
        // TODO
        Grammar *parse_tree = pGrammar(str);
        if (parse_tree) {
            parse_tree->accept(this);
        }
    }

    void PCFGRuleParser::visitGrammar(Grammar *t) { } //abstract class
    void PCFGRuleParser::visitRule(Rule *t) { } //abstract class
    void PCFGRuleParser::visitLHS(LHS *t) { } //abstract class
    void PCFGRuleParser::visitProb(Prob *t) { } //abstract class
    void PCFGRuleParser::visitSYM(SYM *t) { } //abstract class
    void PCFGRuleParser::visitT(T *t) { } //abstract class
    void PCFGRuleParser::visitRHS(RHS *t) { } //abstract class

    void PCFGRuleParser::visitGram(Gram *gram) {
        /* Code For Gram Goes Here */

        gram->listrule_->accept(this);

    }

    void PCFGRuleParser::visitRul(Rul *rul) {
        /* Code For Rul Goes Here */

        rul->prob_->accept(this);
        rul->lhs_->accept(this);
        rul->listrhs_->accept(this);

    }

    void PCFGRuleParser::visitERul(ERul *e_rul) {
        /* Code For ERul Goes Here */
    }

    void PCFGRuleParser::visitLhsS(LhsS *lhs_s) {
        /* Code For LhsS Goes Here */

        visitIdent(lhs_s->ident_);

    }

    void PCFGRuleParser::visitProbS(ProbS *prob_s) {
        /* Code For ProbS Goes Here */

        visitDouble(prob_s->double_);

    }

    void PCFGRuleParser::visitSymb(Symb *symb) {
        /* Code For Symb Goes Here */

        visitIdent(symb->ident_);

    }

    void PCFGRuleParser::visitSymbPlus(SymbPlus *symb_plus) {
        /* Code For SymbPlus Goes Here */

        visitIdent(symb_plus->ident_);

    }

    void PCFGRuleParser::visitSymbAst(SymbAst *symb_ast) {
        /* Code For SymbAst Goes Here */

        visitIdent(symb_ast->ident_);

    }

    void PCFGRuleParser::visitSymbOpt(SymbOpt *symb_opt) {
        /* Code For SymbOpt Goes Here */

        visitIdent(symb_opt->ident_);

    }

    void PCFGRuleParser::visitTerm(Term *term) {
        /* Code For Term Goes Here */

        visitString(term->string_);

    }

    void PCFGRuleParser::visitTermPlus(TermPlus *term_plus) {
        /* Code For TermPlus Goes Here */

        visitString(term_plus->string_);

    }

    void PCFGRuleParser::visitTermAst(TermAst *term_ast) {
        /* Code For TermAst Goes Here */

        visitString(term_ast->string_);

    }

    void PCFGRuleParser::visitTermOpt(TermOpt *term_opt) {
        /* Code For TermOpt Goes Here */

        visitString(term_opt->string_);

    }

    void PCFGRuleParser::visitRhsS(RhsS *rhs_s) {
        /* Code For RhsS Goes Here */

        rhs_s->sym_->accept(this);

    }

    void PCFGRuleParser::visitRhsSR(RhsSR *rhs_sr) {
        /* Code For RhsSR Goes Here */

        rhs_sr->sym_->accept(this);
        rhs_sr->listrhs_->accept(this);

    }

    void PCFGRuleParser::visitRhsT(RhsT *rhs_t) {
        /* Code For RhsT Goes Here */

        rhs_t->t_->accept(this);

    }

    void PCFGRuleParser::visitRhsTR(RhsTR *rhs_tr) {
        /* Code For RhsTR Goes Here */

        rhs_tr->t_->accept(this);
        rhs_tr->listrhs_->accept(this);

    }

    void PCFGRuleParser::visitRhsBr(RhsBr *rhs_br) {
        /* Code For RhsBr Goes Here */

        rhs_br->listrhs_->accept(this);

    }

    void PCFGRuleParser::visitRhsBrPlus(RhsBrPlus *rhs_br_plus) {
        /* Code For RhsBrPlus Goes Here */

        rhs_br_plus->listrhs_->accept(this);

    }

    void PCFGRuleParser::visitRhsBrAst(RhsBrAst *rhs_br_ast) {
        /* Code For RhsBrAst Goes Here */

        rhs_br_ast->listrhs_->accept(this);

    }

    void PCFGRuleParser::visitRhsBrOpt(RhsBrOpt *rhs_br_opt) {
        /* Code For RhsBrOpt Goes Here */

        rhs_br_opt->listrhs_->accept(this);

    }


    void PCFGRuleParser::visitListRHS(ListRHS *list_rhs) {
        for (ListRHS::iterator i = list_rhs->begin(); i != list_rhs->end(); ++i) {
            (*i)->accept(this);
        }
    }

    void PCFGRuleParser::visitListRule(ListRule *list_rule) {
        for (ListRule::iterator i = list_rule->begin(); i != list_rule->end(); ++i) {
            (*i)->accept(this);
        }
    }


    void PCFGRuleParser::visitInteger(Integer x) {
        /* Code for Integer Goes Here */
    }

    void PCFGRuleParser::visitChar(Char x) {
        /* Code for Char Goes Here */
    }

    void PCFGRuleParser::visitDouble(Double x) {
        /* Code for Double Goes Here */
    }

    void PCFGRuleParser::visitString(String x) {
        /* Code for String Goes Here */
    }

    void PCFGRuleParser::visitIdent(Ident x) {
        /* Code for Ident Goes Here */
    }

}