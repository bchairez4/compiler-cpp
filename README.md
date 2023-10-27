# compiler-cpp

Created by Brian Chairez

Creating a compiler in C++ that converts C++ source code into assembly code.

The compiler works by taking in the C++ source code and running it through four phases.

The first phase of the compiler is the Lexical Analysis Phase in which the code is scanned from top to bottom, left to right while ignoring all white spaces and comments and is organized into tokens and lexemes. 
A lexeme is a sequence of characters and a token is the grouping that describes the basic units of the C++ programming language. 

The second phase of the compiler is the Syntactical Analysis Phase in which all tokens from the previous phase are taken and used to construct a parse tree in the proper grammatical format according to the C++ programming language. 
Syntactical Analysis only concerns itself with the hierarchical representation of the source code.
