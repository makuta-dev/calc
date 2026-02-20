#include "Parser.h"

#include <iostream>
#include <ostream>

namespace calc {

    Parser::Parser(const std::vector<Token>& tokens) {
        m_tokens = tokens;
        m_index = 0;
    }

    NodePtr Parser::getRoot() {
        return parseExpression();
    }

    NodePtr Parser::parseExpression(){
        auto left = parseTerm();

        while (isOk() && (current().word == Word::Plus || current().word == Word::Minus)) {
            const auto op = current().word;
            m_index++;
            auto right = parseTerm();
            left = std::make_unique<CBinary>(op,std::move(left),std::move(right));
        }

        return left;
    }

    NodePtr Parser::parseTerm() {
        auto left = parseFactor();

        while (isOk() && (current().word == Word::Asterisk || current().word == Word::Slash  ||
            current().word == Word::Power || current().word == Word::Percent)) {
            const auto op = current().word;
            m_index++;
            auto right = parseFactor();
            left = std::make_unique<CBinary>(op,std::move(left),std::move(right));
        }

        return left;
    }

    NodePtr Parser::parseFactor() {
        if (isOk() && current().word == Word::Number) {
            const auto val = current().value;
            m_index++;
            auto number = std::make_unique<CNumber>(val);
            if (isOk() && current().word == Word::Factorial) {
                const auto op = current().word;
                m_index++;
                return std::make_unique<CUnary>(op,std::move(number));
            }
            return number;
        }

        if (isOk() && current().word == Word::LeftParen) {
            m_index++;
            auto expr = parseExpression();
            if(isOk() && current().word == Word::RightParen) {
                m_index++;
            }else {
                throw std::logic_error("Missing ')'");
            }
            return expr;
        }

        if (isOk() && current().word == Word::Minus) {
            m_index++;
            auto expr = parseFactor();
            return std::make_unique<CUnary>(Word::Minus,std::move(expr));
        }

        std::cout << "Catch: " << current() << std::endl;
        throw std::logic_error("");
    }

    Token Parser::current() const {
        return m_tokens[m_index];
    }

    bool Parser::isOk() const {
        return m_index < m_tokens.size();
    }
}
