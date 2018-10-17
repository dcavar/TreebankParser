# TreebankParser

(C) 2016-2018 by [Damir Cavar] <[dcavar@iu.edu](mailto:dcavar@iu.edu)>

This code and the binaries are made available under the
[Apache License, Version 2.0, January 2004](http://www.apache.org/licenses/). For details see the included
*LICENSE.txt* file.



This is a tool that reads treebank files and generates a probabilistic grammar for use in [FLE].

Currently it can generate all Context-free Grammar rules from a treebank in the Penn-treebank format.

Take for example the *test1.txt* file in the current source repository. You can run treebankparser to generate a frequency profile of the rules:

	./treebankparser -y S test1.txt

The *-y S* parameter generates an S-symbol for empty root nodes, as in *test1.txt*. The default is to generate *ROOT* as the label for such root nodes.

The out put should look like this:

	1	ADJP --> JJ
	1	IP-HLN --> VP
	1	JJ --> 重要
	1	NN --> 企业
	1	NN --> 增长点
	1	NN --> 外商
	1	NN --> 外贸
	1	NN --> 投资
	2	NP --> NN
	1	NP --> NP
	1	NP-OBJ --> NP
	1	NP-PN --> NR
	1	NP-SBJ --> NN NN NN
	1	NR --> 中国
	1	S --> IP-HLN
	1	VP --> NP-OBJ
	1	VV --> 成为

The probability is tab-delimited from the rule. It can also be generated as a float using the *-r* parameter:

	./treebankparser -r -y S test1.txt > res.log

The output should look like:

	0.0555556       ADJP --> JJ
	0.0555556       IP-HLN --> VP
	0.0555556       JJ --> 重要
	0.0555556       NN --> 企业
	0.0555556       NN --> 增长点
	0.0555556       NN --> 外商
	0.0555556       NN --> 外贸
	0.0555556       NN --> 投资
	0.111111        NP --> NN
	0.0555556       NP --> NP
	0.0555556       NP-OBJ --> NP
	0.0555556       NP-PN --> NR
	0.0555556       NP-SBJ --> NN NN NN
	0.0555556       NR --> 中国
	0.0555556       S --> IP-HLN
	0.0555556       VP --> NP-OBJ
	0.0555556       VV --> 成为


The rules are printed to standard out with absolute or relative frequencies.

I am adding more features, e.g.:
 
- reloading existing grammars (multi-batch cycles for larger corpus collections)
- elimination of terminal rules
- parsing alternative coding formats for syntactic trees or treebanks (e.g. XML, TEI XML)
- output probabilities for Left-hand-side symbols only, rather than rules
- generation of a Weighted Finite State Transducer representation, as coded in [FLE]

If you have ideas or suggestions, let me know.




## Prerequisites

The tool is written in [C++11] and requires the following libraries:

- [Boost]
- [Xerces-C++]


## Compile

Use [CLion] or otherwise run:

	cmake CMakeLists.txt
	make



[Damir Cavar]: http://damir.cavar.me/ "Damir Cavar"
[CLion]: https://www.jetbrains.com/clion/ "CLion IDE"
[Boost]: http://www.boost.org/ "Boost C++ Libraries"
[C++11]: https://en.wikipedia.org/wiki/C%2B%2B11 "C++11"
[Xerces-C++]: https://xerces.apache.org/xerces-c/ "Xerces-C++ XML Parser"
[FLE]: http://gorilla.linguistlist.org/fle/ "Free Linguistic Environment"

