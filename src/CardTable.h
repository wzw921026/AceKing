#include <vector>
#include <algorithm>

#include "Card.h"

typedef std::pair<bool, std::vector<int>> CardType;

class CardTable {
public:    
    CardTable();
    int add_card(Card card);
    CardType isStraightFlush();
    CardType isFourOfAKind();
    CardType isFullHouse();
    CardType isFlush();
    CardType isStraight();
    CardType isThreeOfAKind();
    CardType isTwoPairs();
    CardType isOnePair();
    CardType isNoPair();

private:
    std::vector<int> num_cnt;
    std::vector<int> col_cnt;
    std::vector<std::vector<int>> col_rec;
};
