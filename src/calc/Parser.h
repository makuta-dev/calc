#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <vector>

#include "AST.h"
#include "Token.h"

namespace calc {

    class Parser final {
    public:
        explicit Parser(const std::vector<Token>& tokens);
        NodePtr getRoot();

    private:
        NodePtr parseTerm();
        NodePtr parseFactor();

        [[nodiscard]] Token current() const;
        [[nodiscard]] bool isOk() const;

        std::size_t m_index;
        std::vector<Token> m_tokens;
    };

}

#endif //CALC_PARSER_H