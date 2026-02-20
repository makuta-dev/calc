#include "AST.h"

#include <cmath>
#include <iostream>
#include <ostream>

namespace calc {

    CNumber::CNumber(const float data) {
        m_value = data;
    }

    float CNumber::evaluate() {
        return m_value;
    }

    CBinary::CBinary(const Word op, NodePtr&& left, NodePtr&& right) {
        m_op = op;
        m_left = std::move(left);
        m_right = std::move(right);
    }

    float CBinary::evaluate() {
        if (m_left != nullptr && m_right != nullptr) {
            const float left = m_left->evaluate();
            const float right = m_right->evaluate();
            switch (m_op) {
                case Word::Plus:
                    return left + right;
                case Word::Minus:
                    return left - right;
                case Word::Slash:
                    return left / right;
                case Word::Asterisk:
                    return left * right;
                case Word::Power:
                    return std::pow(left ,right);
                case Word::Percent:
                    return std::fmodf(left,right);
                default:
                    std::cout << "Bad binary operator" << std::endl;
                    break;
            }
        }
        std::cout << "Cannot evaluate: left or right values are NULL" << std::endl;
        return -1.0f;
    }

    CUnary::CUnary(const Word op, NodePtr&& right) {
        m_op = op;
        m_right = std::move(right);
    }

    float fact(const float n) {
        const auto i = static_cast<long>(std::floor(n));
        if (i <= 1) {
            return 1.f;
        }

        int result = 1;
        for (int j = 2; j <= i; j++) {
            result *= j;
        }
        return static_cast<float>(result);
    }

    float CUnary::evaluate() {
        if (m_right != nullptr) {
            const float right = m_right->evaluate();
            switch (m_op) {
                case Word::Minus:
                    return -right;
                case Word::Factorial:
                    return fact(right);
                default:
                    std::cout << "Bad unary operator" << std::endl;
                    break;
            }
        }
        std::cout << "Cannot evaluate: right value is NULL" << std::endl;
        return -1.0f;
    }

}
