# PCFG BNFC

Created: 2016-03-04 by Damir Cavar <[dcavar@iu.edu](mailto:dcavar@iu.edu)>

This code and the binaries are made available under the
[Apache License, Version 2.0, January 2004](http://www.apache.org/licenses/). For details see the included
*LICENSE.txt* file.


## Building

To build the documentation and parser code run:

	./build.sh


## Description

This BNF defines a more complex PCFG-rule formalism than actually is used by
TreeBankParserSA. See the included *test.txt* grammar example. The parser
can processes a relative-frequency grammar that makes use of rules using
the following notation:

	0.000455	S --> NP VP

It can also process rules with annotated absolute frequencies:

	34	S --> NP VP

If it encounters the use of absolute and relative frequency annotations of
rules, it will through an error, i.e. fail to parse the grammar file.


# Repairing bugs

The *build.sh* script uses BNFC to build the LaTeX and PDF documentation and generate the C++ clases. Various issues with the BNFC code generation of the flex and bison code are caught and repaired as well. New versions of BNFC might not generate the issues. Remove the *sed* lines in *build.sh*, if the attempted repairs are causing problems.

