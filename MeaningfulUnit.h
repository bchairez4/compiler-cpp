#ifndef MEANINGFULUNIT_h
#define MEANINGFULUNIT_H

#include <string>

class MeaningfulUnit {
    private:
        std::string token_;
        std::string lexeme_;
    public:
        MeaningfulUnit() : token_("unknown"), lexeme_("unknown") {}

        MeaningfulUnit(const std::string& token, const std::string& lexeme) : token_(token), lexeme_(lexeme) {}

        MeaningfulUnit(const MeaningfulUnit& other) : token_(other.token_), lexeme_(other.lexeme_) {}

        ~MeaningfulUnit() {}

        MeaningfulUnit& operator=(const MeaningfulUnit& other) {
            token_ = other.token_;
            lexeme_ = other.lexeme_;

            return *this;
        }

        std::string getToken() const {
            return token_;
        }

        std::string getLexeme() const {
            return lexeme_;
        }

        void setToken(const std::string& token) {
            token_ = token;
        }

        void setLexeme(const std::string& lexeme) {
            lexeme_ = lexeme;
        } 
};

#endif
