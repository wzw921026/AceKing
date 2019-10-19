#include <string>

class Card {
public:
    Card() = delete;
    Card(int _num, int _col) : num(_num), col(_col) {}
    Card(std::string s);

private:
    int col;
    int num;
};
