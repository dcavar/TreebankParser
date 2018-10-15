# TreebankParser

(C) 2016-2018 by [Damir Cavar] <[dcavar@iu.edu](mailto:dcavar@iu.edu)>


## Introduction

This is a tool that reads treebank files and generates a probabilistic context free grammars (PCFG) for use in [FLE] and other PCFG-based parsers.

Currently it can generate all Context-free Grammar rules from a treebank in the Penn-treebank format.

The rules are printed to standard out with absolute or relative frequencies.

I am working on more features, e.g.:

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

A Java and Scala based version is in the development pipeline.


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
