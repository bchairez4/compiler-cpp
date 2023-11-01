#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <cctype> //toupper
#include <fstream>
#include <vector>

#include "MeaningfulUnit.h"

#define SEPARATOR "Separator"
#define OPERATOR "Operator"
#define KEYWORD "Key Word"
#define IDENTIFIER "Identifier"
#define NUMBER "Number"

class LexicalAnalyzer {
    private:
        char alphaCharacters_[27] = {'_', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        char digits_[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char separators_[8] = {',', ';', '{', '}', '(', ')', '[', ']'};
        std::string keywords_[13] = {"bool", "char", "do", "double", "else", "false", "for", "float", "int", "if", "return", "true", "while"};
        std::string operators_[7] = {"=", "==", "!=", "<", ">", "<=", ">="};
        int validIdentifierDFA_[3][3] = {{1, 2, 2}, {1, 1, 2}, {2, 2, 2}}; 
    public:
        LexicalAnalyzer(const std::string& file, std::vector<MeaningfulUnit>& meaningfulUnits) {
            readFile(file, meaningfulUnits);
        }

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

        bool isNumber(const std::string& number) const {
            for (const char& digit : number) {
                if (!isDigit(digit)) {
                    return false;
                }
            }

            return true;
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

        void readFile(const std::string& file, std::vector<MeaningfulUnit>& units) {
            std::ifstream infile(file, std::ifstream::in);

            if (!infile) {
                return;
            }

            while (!infile.eof()) {
                std::string word = "";

                while (infile >> word) {
                    MeaningfulUnit unit;
                    std::string tempSeparator = "";
                    bool foundTempSeparator = false;

                    // Check first character if separator
                    if (word.size() > 1 && isSeparator(word[0])) {
                        std::string separator = "";
                        separator = word[0];
                        unit.update(SEPARATOR, separator);
                        units.push_back(unit);
                        word.erase(word.begin());
                    }

                    // Check last character if separator
                    if (word.size() > 1 && isSeparator(word[word.length() - 1])) {
                        tempSeparator = word[word.length() - 1];
                        foundTempSeparator = true;
                        word.erase(word.end() - 1);
                    }

                    if (isSeparator(word[0])) {
                        unit.update(SEPARATOR, word);
                    } else if (isOperator(word)) {
                        unit.update(OPERATOR, word);
                    } else if (isKeyword(word)) {
                        unit.update(KEYWORD, word);
                    } else if (isNumber(word)) {
                        unit.update(NUMBER, word);
                    } else if (isValidIdentifier(word)) {
                        unit.update(IDENTIFIER, word);
                    }

                    units.push_back(unit);

                    if (foundTempSeparator) {
                        unit.update(SEPARATOR, tempSeparator);
                        units.push_back(unit);
                        foundTempSeparator = false;
                    }
                }

            }

            infile.close();
        }
};

#endif
