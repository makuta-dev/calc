#include "Lexer.h"

#include <iomanip>
#include <iostream>
#include <ostream>

namespace calc {

    namespace details {

        bool is_digit(const char c) {
            return std::string("0123456789").find(c) != std::string::npos;
        }

        bool is_space(const char c) {
            return std::string(" \t\n\r").find(c) != std::string::npos;
        }

    }

    Lexer::Lexer(const std::string_view& input) : m_index(0), m_input(input) {

    }

    std::vector<Token> Lexer::lex() {
        auto items = std::vector<Token>();

        const auto ch = [this] {
            return m_input[m_index];
        };

        const auto put = [&items](const Token token) {
            return items.push_back(token);
        };

        while (m_index < m_input.length()) {

            if (details::is_space(ch())) {
                m_index++;
                continue;
            }

            if (details::is_digit(ch())) {
                put(lexNumber());
                continue;
            }
            if (ch() == '+') {
                put({Word::Plus,0.f});
            }
            else if (ch() == '-') {
                put({Word::Minus,0.f});
            }
            else if (ch() == '*') {
                put({Word::Asterisk,0.f});
            }
            else if (ch() == '/') {
                put({Word::Slash,0.f});
            }
            else {
                std::cerr << "Unknown character:" << ch() << std::endl;
            }

            m_index++;
        }

        return items;
    }

    Token Lexer::lexNumber() {
        const auto start = m_index;
        while (m_index < m_input.length() && details::is_digit(m_input[m_index])) {
            m_index++;
        }
        if (m_index < m_input.length() && m_input[m_index] == '.') {
            m_index++;
            while (m_index < m_input.length() && details::is_digit(m_input[m_index])) {
                m_index++;
            }
        }
        const auto buffer = std::string(m_input.substr(start, m_index - start));
        float value;
        try {
            value = std::stof(buffer);
        } catch (std::exception& e) {
            value = 0.f;
            std::cerr << "Cannot transform "<< std::quoted(buffer) << " into number: " << e.what() << std::endl;
        }
        return Token{Word::Number,value};
    }

}
