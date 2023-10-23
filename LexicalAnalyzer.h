#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <cctype>
#include <iostream>
#include <vector>

#include "MeaningfulUnit.h"

class LexicalAnalyzer {
    private:
        char alphaCharacters_[27] = {'_', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        char digits_[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char separators_[8] = {',', ';', '{', '}', '(', ')', '[', ']'};
        std::string keywords_[13] = {"bool", "char", "do", "double", "else", "false", "for", "float", "int", "if", "return", "true", "while"};
        std::string operators_[7] = {"=", "==", "!=", "<", ">", "<=", ">="};
        int validIdentifierDFA_[3][3] = {{1, 2, 2}, {1, 1, 2}, {2, 2, 2}}; 
    public:
        LexicalAnalyzer() {}

        LexicalAnalyzer(const LexicalAnalyzer& other) {} 

        ~LexicalAnalyzer() {}

        LexicalAnalyzer& operator=(const LexicalAnalyzer& other) {
            return *this;
        }

        bool isAlphabetic(const char& character) const {
            for (const char& ch : alphaCharacters_) {
                if (character == ch) {
                    return true;
                }
            }

            return false;
        }

        bool isDigit(const char& character) const {
            for (const char& digit : digits_) {
                if (character == digit) {
                    return true;
                }
            }

            return false;
        }

        bool isSeparator(const char& character) const {
            for (const char& separator : separators_) {
                if (character == separator) {
                    return true;
                }
            }

            return false;
        }

        bool isKeyword(const std::string& word) const {
            for (const std::string& w : keywords_) {
                if (word == w) {
                    return true;
                }
            }

            return false;
        }

        bool isOperator(const std::string& symbol) const {
            for (const std::string& op : operators_) {
                if (symbol == op) {
                    return true;
                }
            }

            return false;
        }

        bool isValidIdentifier(const std::string& word) const {
            int row = 0, col = 0, state = 0;

            for (const char& character : word) {
                if (isAlphabetic(std::toupper(character))) {
                    col = 0;
                    state = validIdentifierDFA_[row][col];
                    row = state;
                } else if (isDigit(character)) {
                    col = 1;
                    state = validIdentifierDFA_[row][col];
                    row = state;
                } else {
                    col = 2;
                    state = validIdentifierDFA_[row][col];
                    row = state;
                }
            }

            return (state == 1 ? true : false);
        }
};

#endif
