// C++ compiler 
// Created by Brian Chairez

#include "LexicalAnalyzer.h"

#define SOURCE_FILE "sample.txt"

class Compiler {
    private:
        std::vector<MeaningfulUnit> meaningfulUnits_;
    public:
        Compiler() {
            LexicalAnalyzer phase1(SOURCE_FILE, meaningfulUnits_);
        }

        Compiler(const Compiler& other) {}

        ~Compiler() {}

        Compiler& operator=(const Compiler& other) {
            return *this;
        }
};
