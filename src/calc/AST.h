#ifndef CALC_AST_H
#define CALC_AST_H

#include <memory>

#include "Word.h"

namespace calc {

    struct ASTNode {
        virtual ~ASTNode() = default;

        virtual float evaluate() = 0;
    };

    using NodePtr = std::unique_ptr<ASTNode>;

    struct CNumber : ASTNode {
        explicit CNumber(float data);
        ~CNumber() override = default;

        float evaluate() override;

    private:
        float m_value;
    };

    struct CBinary : ASTNode {
        explicit CBinary(Word op, NodePtr&& left, NodePtr&& right);
        ~CBinary() override = default;

        float evaluate() override;

    private:
        Word m_op;
        NodePtr m_left;
        NodePtr m_right;
    };

    struct CUnary : ASTNode {
        explicit CUnary(Word op, NodePtr&& right);
        ~CUnary() override = default;

        float evaluate() override;

    private:
        Word m_op;
        NodePtr m_right;
    };

}

#endif //CALC_AST_H