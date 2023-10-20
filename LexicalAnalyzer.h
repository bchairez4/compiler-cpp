#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <iostream>
#include <string>
#include <vector>

class LexicalAnalyzer {
    private:
        char alphaCharacters_[27] = {'_', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        char digits_[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char separators_[8] = {',', ';', '{', '}', '(', ')', '[', ']'};
        std::string keywords_[13] = {"bool", "char", "do", "double", "else", "false", "for", "float", "int", "if", "return", "true", "while"};
        std::string operators_[7] = {"=", "==", "!=", "<", ">", "<=", ">="};
    public:
        LexicalAnalyzer() {}

        LexicalAnalyzer(const LexicalAnalyzer& other) {} 

        ~LexicalAnalyzer() {}

        LexicalAnalyzer& operator=(const LexicalAnalyzer other) {}
};

#endif
