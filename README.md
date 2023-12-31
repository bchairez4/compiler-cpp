# compiler-cpp

Created by Brian Chairez

Creating a compiler in C++ that converts C++ source code into assembly code.

The compiler works by taking in the C++ source code and running it through four phases.

The first phase of the compiler is the Lexical Analysis Phase in which the code is scanned from top to bottom, left to right while ignoring all white spaces and comments and is organized into tokens and lexemes. 
A lexeme is a sequence of characters and a token is the grouping that describes the basic units of the C++ programming language. 

The second phase of the compiler is the Syntax Analysis Phase in which all tokens from the previous phase are taken and used to construct a parse tree in the proper grammatical format according to the C++ programming language. 
Syntax Analysis only concerns itself with the hierarchical representation of the source code.

The third phase of the compiler is the Semantic Analysis Phase in which the parse tree created from the Syntactical Analysis Phase is verified for semantic correctness. 
Semantic Analysis only concerns itself with whether the parse tree is meaningful or not. 

The fourth phase of the compiler is the Intermediate Code Generator Phase in which the source code is translated into Assembly code. 
The generated Assembly code can be readily executed by the machine. 

In conclusion, the compiler will take a source file, categorize it's content into meaningful units, create a context grammar tree, ensure said tree is valid, then generate rudimentary assembly code. 
The format in which the assembly code will be generated is written onto a .txt file.
