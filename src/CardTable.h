#include <vector>
#include <algorithm>

#include "Card.h"

class CardTable {
public:
    CardTable();
    int add_card(Card card);
    int isStraightFlush();

private:
    std::vector<int> num_cnt;
    // std::vector<int> col_cnt;
    std::vector<std::vector<int>> col_rec;
};
