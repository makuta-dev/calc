#include "Word.h"

#include <iostream>
#include <string>

namespace calc {

    std::ostream& operator<<(std::ostream& os, const Word& word) {
        std::string value;

        switch (word) {
            case Word::Number:
                value = "number";
                break;
            case Word::Plus:
                value = "plus";
                break;
            case Word::Minus:
                value = "minus";
                break;
            case Word::Slash:
                value = "slash";
                break;
            case Word::Asterisk:
                value = "asterisk";
                break;
            case Word::LeftParen:
                value = "lparen";
                break;
            case Word::RightParen:
                value = "rparen";
                break;
            default:
                value = "UNKNOWN";
                break;
        }

        os << value;
        return os;
    }

}