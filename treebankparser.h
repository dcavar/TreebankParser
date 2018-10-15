/**
 * \file treebankparser.h
 *
 * \brief Main treebank-parser class hedader file.
 *
 * \author Damir Cavar &lt;dcavar@iu.edu&gt;
 *
 * \version 0.1
 *
 * \date 2016/09/10 16:20:00
 *
 * \date Created on: Mon September 10 16:20:00 2016
 *
 * \copyright Copyright 2016 by Damir Cavar
 *
 * \license{Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.}
 *
 * \note This needs some more coding.
 *
 * \bug None
 */


#ifndef PCFG_TREEBANKPARSER_H
#define PCFG_TREEBANKPARSER_H


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <numeric>
#include <set>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>


using namespace std;


class TreebankParser {

public:
    TreebankParser();

    ~TreebankParser();

    void processFiles(vector<string> treebankfiles);

    bool parseBrackets(string content);

    void saveToFile(string fname, bool writeterminalrules);

    void printToStream(bool writeterminalrules, ostream &buf);

    void printToStdout(bool writeterminalrules);

    void loadGrammar(string fname);

    void tagTerminalRules();

    string grammarfile;

    string rootsymbol;

    bool relcounts = false; // relative frequencies

    bool symbolcounts = false ; // count the frequency of the LHS symbol rather than the rule

    set<unsigned long> terminalRules;

    map<vector<string>, unsigned long> rules;

};


#endif //PCFG_TREEBANKPARSER_H
