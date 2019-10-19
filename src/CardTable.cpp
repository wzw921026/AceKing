#include "CardTable.h"

CardTable::CardTable() {
    num_cnt.resize(15);
    col_cnt.resize(4);
    col_rec.resize(4);
}

int CardTable::add_card(Card card) {
    ++ num_cnt[card.num];
    ++ col_cnt[card.col];
    col_rec[card.col].push_back(card.num);
    if (card.num == 14) {
        ++ num_cnt[1];
        col_rec[card.col].push_back(1);
    }
}

CardType CardTable::isStraightFlush() {
    std::vector<int> vec;
    for (int i = 0; i < 4; ++i) {
        if (col_cnt[i] < 5) continue;
        sort(col_rec[i].begin(), col_rec[i].end());

        for (int j = col_rec[i].size() - 1; j - 4 >= 0; --j) {
            if (col_rec[i][j] - 4 == col_rec[i][j-4]) {
                vec.push_back(col_rec[i][j]);
                return std::make_pair(true, vec);
            }
        }
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isFourOfAKind() {
    std::vector<int> vec;
    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] == 4) {
            vec.push_back(i);
            break;
        }
    }
    if (vec.empty()) return std::make_pair(false, vec);

    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] > 0 && i != vec[0]) {
            vec.push_back(i);
            return std::make_pair(true, vec);
        }
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isFullHouse() {
    std::vector<int> vec;
    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] == 3) {
            vec.push_back(i);
            break;
        }
    }
    if (vec.empty()) return std::make_pair(false, vec);

    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] >= 2 && i != vec[0]) {
            vec.push_back(i);
            return std::make_pair(true, vec);
        }
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isFlush() {
    std::vector<int> vec;
    for (int i = 0; i < 4; ++i) {
        if (col_cnt[i] < 5) continue;
        sort(col_rec[i].begin(), col_rec[i].end());

        for (int j = col_rec[i].size() - 1; j >= col_rec[i].size() - 5; --j) {
            vec.push_back(j);
        }
        return std::make_pair(true, vec);
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isStraight() {
    std::vector<int> vec;
    for (int i = 14; i >= 5; --i) {
        bool flag = true;
        for (int j = i; j >= i - 4; --j) {
            if (num_cnt[j] == 0) flag = false;
        }
        if (flag) {
            vec.push_back(i);
            return std::make_pair(true, vec);
        }
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isThreeOfAKind() {
    std::vector<int> vec;
    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] == 3) {
            vec.push_back(i);
            break;
        }
    }
    if (vec.empty()) return std::make_pair(false, vec);

    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] > 0 && i != vec[0]) {
            vec.push_back(i);
            if (vec.size() == 3) return std::make_pair(true, vec);
        }
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isTwoPairs() {
    std::vector<int> vec;
    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] == 2) {
            vec.push_back(i);
            if (vec.size() == 2) break;
        }
    }
    if (vec.size() < 2) return std::make_pair(false, vec);

    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] > 0 && i != vec[0] && i != vec[1]) {
            vec.push_back(i);
            return std::make_pair(true, vec);
        }
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isOnePair() {
    std::vector<int> vec;
    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] == 2) {
            vec.push_back(i);
            break;
        }
    }
    if (vec.empty()) return std::make_pair(false, vec);

    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] > 0 && i != vec[0]) {
            vec.push_back(i);
            if (vec.size() == 4) return std::make_pair(true, vec);
        }
    }

    return std::make_pair(false, vec);
}

CardType CardTable::isNoPair() {
    for (int i = 14; i >= 2; --i) {
        if (num_cnt[i] > 0) {
            vec.push_back(i);
            if (vec.size() == 5) return std::make_pair(true, vec);
        }
    }

    return std::make_pair(false, vec);
}
