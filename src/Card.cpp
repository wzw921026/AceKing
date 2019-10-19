#include "Card.h"

Card::Card(const char* ch) {
    std::string s(ch);
    if (s.size() != 2)
        return;

    char c = tolower(s[1]);
    if (c == 's') {
        col = 0;
    }
    else if (c == 'h') {
        col = 1;
    }
    else if (c == 'c') {
        col = 2;
    }
    else if (c == 'd') {
        col = 3;
    }
    else {
        return;
    }

    c = toupper(s[0]);
    if (c == 'A') {
        num = 14;
    }
    else if (c == 'K') {
        num = 13;
    }
    else if (c == 'Q') {
        num = 12;
    }
    else if (c == 'J') {
        num = 11;
    }
    else if (c == 'T') {
        num = 10;
    }
    else {
        num = c - '0';
    }

    if (num < 2)
        return;

    return;
}
