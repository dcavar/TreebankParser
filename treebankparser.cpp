/**
 * \file treebankparser.cpp
 *
 * \brief Main treebank-parser class.
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


#include "treebankparser.h"


TreebankParser::TreebankParser() {
    grammarfile = "";
    rootsymbol = "ROOT";
}


TreebankParser::~TreebankParser() {

}


void TreebankParser::processFiles(vector<string> treebankfiles) {
    // load grammar
    ifstream ipf;
    ipf.exceptions(ifstream::failbit | ifstream::badbit);
    stringstream strbuffer;

    for (auto filename : treebankfiles) {
        try {
            ipf.open(filename.c_str(), ios::in);
            if (ipf.is_open()) {
                while (!ipf.eof()) {
                    ipf >> strbuffer.rdbuf();
                }
            }
        } catch (ifstream::failure e) {
            cout << "Cannot read file " << filename << "! Skipping..." << endl;
        }
        ipf.close();
        if (!parseBrackets(strbuffer.str())) {
            cout << "Error: Bracket mismatch in file: " << filename << "! Skipping..." << endl;
        }
    }
}


void TreebankParser::loadGrammar(string fname) {

}


void TreebankParser::tagTerminalRules() {

}


bool TreebankParser::parseBrackets(string content) {
    // keep list of opening and closing brackets as they match
    vector<unsigned long> opening;

    // storage buffer for local levels
    map<int, vector<string>> levels;

    for (string::size_type i = 0; i < content.size(); ++i) {
        if (content[i] == '(') {
            opening.push_back(i);
            continue;
        }
        if (content[i] == ')') {
            unsigned long count = opening.size();
            if (count > 0) {
                unsigned long from = opening[count - 1];
                string subtree = content.substr(from + 1, i - from - 1);
                // store level information for each parsed bracket,
                // when hitting closing check whether it is closing with bracketed structure inside,
                // fetch all children from the level below and generate RHS
                // if there is no ( or ) this is a terminal
                unsigned long pos = subtree.find("(");
                if (pos != string::npos) {
                    // the node label is LHS and all daughters from level +1 are RHS
                    int level = opening.size();
                    // get the string between the ( and the next (
                    vector<string> strs;
                    string res = subtree.substr(0, pos);
                    boost::trim(res);
                    boost::split(strs, res, boost::is_any_of(" "));
                    // if root level and no symbol, use rootsymbol from command line or default
                    if ((level == 1) & (strs.size() == 1) & !strs[0].size()) {
                        strs = vector<string>( {rootsymbol} );
                    }
                    auto const i = levels.find(level + 1);
                    if (i != levels.end()) {
                        vector<string> tmp = i->second;
                        for (auto const &rhs : tmp) {
                            strs.push_back(rhs);
                        }
                    }
                    levels.erase(level + 1); // remove the daughters
                    vector<string> tmp;
                    tmp.push_back(strs[0]);
                    // push back the daughter for this node onto the level
                    levels[level] = tmp;
                    // push on rules map
                    auto const ruleIt = rules.find(strs);
                    unsigned long val = 0;
                    if (ruleIt != rules.end())
                        val = ruleIt->second;
                    rules[strs] = ++val;
                } else {
                    // this is a tag with terminal
                    vector<string> strs;
                    boost::split(strs, subtree, boost::is_any_of(" "));
                    if (strs.size() > 0) {
                        // add to rules and count
                        auto const ruleIt = rules.find(strs);
                        unsigned long val = 0;
                        if (ruleIt != rules.end())
                            val = ruleIt->second;
                        // save the rule
                        rules[strs] = ++val;

                        vector<string> tmp;
                        int level = opening.size();

                        auto const i = levels.find(level);
                        if (i != levels.end())
                            tmp = i->second;

                        // add only the left-hand-side symbol to the buffer
                        tmp.push_back(strs[0]);
                        levels[level] = tmp;
                    }
                }
                opening.pop_back(); // pop matching element
            } else { // mismatch of brackets detected
                return (false);
            }
        }
    }
    /*for (auto const &elem : rules) {
        cout << elem.second << " " << elem.first[0] << " --> ";
        for (int i = 1; i < elem.first.size(); ++i) {
            cout << elem.first[i] << " ";
        }
        cout << endl;
    } */
    return (true);
}


void TreebankParser::saveToFile(string fname, bool writeterminalrules) {
    // create backup of old grammar file
    if (boost::filesystem::exists(fname)) {
        if (boost::filesystem::is_regular_file(fname)) {
            boost::filesystem::rename(fname, fname + ".bak");
        }
    }
    try {
        ofstream fout;
        fout.open(fname);
        ostream *fp = &fout;
        printToStream(writeterminalrules, *fp);
        fout.flush();
        fout.close();
    } catch (ifstream::failure e) {
        cout << "Error writing to file " << fname << endl;
    }
}


void TreebankParser::printToStdout(bool writeterminalrules) {
    ostream *fp = &cout;
    printToStream(writeterminalrules, *fp);
}


void TreebankParser::printToStream(bool writeterminalrules, ostream &buf) {
    const double total = accumulate(begin(rules),
                                    end(rules),
                                    0,
                                    [](const unsigned long previous,
                                       const pair<vector<string>, unsigned long> &rule) {
                                        return previous + rule.second;
                                    });
    unsigned long len;
    for (auto const &rule : rules) {
        if (relcounts)
            buf << double(rule.second) / total;
        else
            buf << rule.second;
        buf << "\t" << rule.first[0] << " --> ";
        len = rule.first.size();
        if (len > 2) {
            for (unsigned long i = 1; i < len - 1; ++i) {
                buf << rule.first[i] << " ";
            }
            buf << rule.first[len - 1] << endl;
        } else {
            buf << rule.first[1] << endl;
        }
    }
}
