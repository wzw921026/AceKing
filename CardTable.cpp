#include "CardTable.h"

CardTable::CardTable() {
    for (int i = 0; i <= 14; ++i)
        num_cnt.push_back(0);
    // for (int i = 0; i < 4; ++i) {
    //     col_cnt.push_back(0);
    // }
    for (int i = 0; i < 4; ++i) {
        col_rec.push_back(std::vector());
    }
}

int CardTable::add_card(Card card) {
    ++ num_cnt[card.num];
    // ++ col_cnt[card.col];
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
