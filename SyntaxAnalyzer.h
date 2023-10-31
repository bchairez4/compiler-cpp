#ifndef SYNTAXANALYZER_H
#define SYNTAXANALYZER_H

class SyntaxAnalyzer {
    public:
        SyntaxAnalyzer() {}

        SyntaxAnalyzer(const SyntaxAnalyzer& other) {}

        ~SyntaxAnalyzer() {}

        SyntaxAnalyzer& operator=(const SyntaxAnalyzer& other) {
            return *this;
        }
};

#endif
