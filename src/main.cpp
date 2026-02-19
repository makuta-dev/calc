#include <iostream>
#include <cmath>
#include <string>

#include "calc/Lexer.h"
#include "calc/Parser.h"

float calculate(const std::string& input) {
    auto lexer = calc::Lexer(input);
    const auto tokens = lexer.lex();
    auto parser = calc::Parser(tokens);
    if (const auto ast_root = parser.getRoot()) {
        return ast_root->evaluate();
    }
    return std::numeric_limits<float>::quiet_NaN();
}

int main(int argc, char** argv) {
    if (argc >= 2) {
        std::cout << calculate(argv[1]) << std::endl;
    } else {
        std::string input;
        while (std::getline(std::cin, input)) {
            if (input.empty()) {
                break;
            }
            std::cout << calculate(input) << std::endl;
        }
    }
    return 0;
}
