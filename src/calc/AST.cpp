#include "AST.h"

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
                default:
                    std::cout << "Bad operator" << std::endl;
                    break;
            }
        }
        std::cout << "Cannot evaluate: left or right values are NULL" << std::endl;
        return -1.0f;
    }

}
