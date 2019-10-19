#include "CardTable.h"

CardTable::CardTable() {
    num_cnt.resize(15);
    col_rec.resize(4);
}

int CardTable::add_card(Card card) {
    ++ num_cnt[card.num];
    col_rec[card.col].push_back(card.num);
}

int CardTable::isStraightFlush() {
    for (int i = 0; i < 4; ++i) {
        if (col_rec[i].size() < 5)
            continue;
        sort(col_rec[i].begin(), col_rec[i].end());

        size_t last = col_rec[i].size() - 1;
        for (int j = last; j - 4 >= 0; --j) {
            if (col_rec[i][j] - 4 == col_rec[i][j-4]) {
                return col_rec[i][j];
            }
        }
        if (col_rec[i][last] == 14 && col_rec[i][3] == 5) {
            return 5;
        }
        return 0;
    }
}
