/**
 * \file main.c
 *
 * \brief Main function for testing the treebank-parser.
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
 * \note This needs some more specification specification and optimization.
 *
 * \bug None
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include "treebankparser.h"


using namespace std;
namespace po = boost::program_options;

namespace {
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 3;
} // namespace

const char _prog_fullname[] = "Probabilistic Grammar Parser";
const char _prog_name[] = "pcfgparser";
const int _version_major = 0;
const int _version_minor = 1;


void usage();

void usage(po::options_description desc) {
    usage();
    cout << desc << endl;
}

/*! \fn void usage( )
    \brief Print out the usage.

    Prints out the copyright without option descriptions.
*/
void usage() {
    cout << _prog_fullname << " (" << _prog_name << ") Version " << _version_major << "." << _version_minor << endl
         << "Usage: treebankparser [TREEBANK_FILES]..." << endl << endl
         << "For help:" << endl << "fle --help" << endl << endl
         << "(C) 2016 by Damir Cavar <dcavar@iu.edu>" << endl << endl;
}


int main(int argc, char *argv[]) {
    bool quiet = false;
    vector<string> processfiles;
    TreebankParser myTP;

    try {
        po::options_description desc("treebankparser options");
        desc.add_options()
                ("help,h", "produce help message")
                ("absolute,a", "return absolute counts")
                ("relative,r", "return relative counts or probabilities for rules")
                ("symbolcounts,s", "return relative counts or probabilities for rules")
                ("rootsymbol,y", po::value<string>(), "symbol for empty tree roots")
                ("grammar,g", po::value<string>(), "use grammar")
                ("quiet,q", "Quiet operations")
                ("version,v", po::value<string>(), "Print version information")
                ("input-files", po::value<vector<string>>(), "Sentences");

        po::positional_options_description p;
        p.add("input-files", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, (const char *const *) argv).options(desc).positional(p).run(), vm);
        //po::store(po::command_line_parser(argc, (const char *const *) argv).options(desc).run(), vm);
        po::notify(vm);

        if (vm.count("help")) {
            usage(desc);
            return SUCCESS;
        }
        if (vm.count("quiet")) {
            quiet = true;
        }
        if (vm.count("version")) {
            cout << _prog_fullname << " (" << _prog_name << ") " << _version_major << "." << _version_minor << endl;
        }
        if (vm.count("absolute")) {
            // Use relative rule counts for probabilities (default)
            myTP.relcounts = false;
        }
        if (vm.count("relative")) {
            // Use relative rule counts for probabilities (default)
            myTP.relcounts = true;
        }
        if (vm.count("symbolcounts")) {
            // Use symbol counts for probabilities
            myTP.symbolcounts = true;
        }
        if (vm.count("rootsymbol")) {
            myTP.rootsymbol = vm["rootsymbol"].as<string>();
        }
        if (vm.count("grammar")) {
            myTP.grammarfile = vm["grammar"].as<string>();
            if (!quiet)
                cout << "Load grammar: " << myTP.grammarfile << endl;
        }
        if (vm.count("input-files")) {
            // only load the grammar, if there is some input to parse
            processfiles = vector<string>(vm["input-files"].as<vector<string>>());
        }
    } catch (exception &e) { // Catch command line error
        string message = e.what();
        if (message.size()) {
            cerr << "Error: " << message << endl;
        }
        usage();
        return ERROR_IN_COMMAND_LINE;
    } catch (...) {  // catch any other error
        cerr << "Unknown error!" << endl;
        return ERROR_UNHANDLED_EXCEPTION;
    }

    /* if (grammar_file.size() == 0) {
        cout << "Please provide a grammar using command line parameters." << endl << endl;
        usage();
        return ERROR_IN_COMMAND_LINE;
    } */

    if (processfiles.size() > 0) {
        // load grammar
        if (myTP.grammarfile.size() > 0)
            myTP.loadGrammar(myTP.grammarfile);
        // process files one by one
        myTP.processFiles(processfiles);
        myTP.printToStdout(false);
    }
    return SUCCESS;

} // main
