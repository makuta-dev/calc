#ifndef CALC_LEXER_H
#define CALC_LEXER_H

#include <string_view>
#include <vector>

#include "Token.h"

namespace calc {

    class Lexer final {
    public:
        explicit Lexer(const std::string_view& input);
        std::vector<Token> lex();

    private:
        Token lexNumber();

        std::size_t m_index;
        std::string_view m_input;
    };

}

#endif //CALC_LEXER_H