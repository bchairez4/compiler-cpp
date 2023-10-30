// C++ compiler 
// Created by Brian Chairez

#include "LexicalAnalyzer.h"
#include "SyntaxAnalyzer.h"
#include "SemanticAnalyzer.h"
#include "IntermediateCodeGenerator.h"

class Compiler {
    private:
        std::vector<MeaningfulUnit> meaningfulUnits_;
    public:
        Compiler() {}

        Compiler(const Compiler& other) {}

        ~Compiler() {}

        Compiler& operator=(const Compiler& other) {}
};
