#include <string>

class Card {
public:
    Card() = delete;
    Card(int _num, int _col) : num(_num), col(_col) {}
    Card(const char* ch);

    int col;
    int num;
};
