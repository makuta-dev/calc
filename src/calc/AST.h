#ifndef CALC_AST_H
#define CALC_AST_H

#include "Word.h"

namespace calc {

    struct ASTNode {
        virtual ~ASTNode() = default;

        virtual float evaluate() = 0;
    };

    struct CNumber : ASTNode {
        explicit CNumber(float data);
        ~CNumber() override = default;

        float evaluate() override;

    private:
        float m_value;
    };

    struct CBinary : ASTNode {
        explicit CBinary(Word op, ASTNode* left, ASTNode* right);
        ~CBinary() override = default;

        float evaluate() override;

    private:
        Word m_op;
        ASTNode* m_left;
        ASTNode* m_right;
    };

}

#endif //CALC_AST_H