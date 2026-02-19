#ifndef CALC_TOKEN_H
#define CALC_TOKEN_H

#include <iosfwd>

#include "Word.h"

namespace calc {

    struct Token final {
        Word word;
        float value;
    };

    std::ostream& operator<<(std::ostream& os, const Token& token);

}

#endif //CALC_TOKEN_H