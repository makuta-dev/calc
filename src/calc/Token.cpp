#include "Token.h"

#include <iostream>

namespace calc {

    std::ostream& operator<<(std::ostream& os, const Token& token) {
        os << "Token{ " << token.word << ", " << token.value << "}";
        return os;
    }

}