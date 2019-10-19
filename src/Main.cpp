#include <iostream>
#include <cstdio>

#include "CardTable.h"
using namespace std;

int main() {
    CardTable card_table;
    card_table.add_card("2d");
    card_table.add_card("3d");
    card_table.add_card("4d");
    card_table.add_card("5d");
    card_table.add_card("Td");
    card_table.add_card("Jd");
    card_table.add_card("Qd");
    card_table.add_card("Kd");
    card_table.add_card("Ad");
    cout << card_table.isStraightFlush() << endl;
}
