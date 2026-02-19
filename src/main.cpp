#include <iostream>
#include <string>

#include "calc/Lexer.h"

int main() {
    const std::string expr = "2.6 + 2.9 * 2.95";
    auto lexer = calc::Lexer(expr);
    for (const auto& token : lexer.lex()) {
        std::cout << token << std::endl;
    }
    return 0;
}
