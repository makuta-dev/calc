#ifndef CALC_WORD_H
#define CALC_WORD_H

#include <iosfwd>

namespace calc {

    enum class Word {
        Number,

        LeftParen,
        RightParen,

        Plus,       // +
        Minus,      // -
        Slash,      // /
        Asterisk,   // *
    };

    std::ostream& operator<<(std::ostream& os, const Word& word);

}

#endif //CALC_WORD_H