#include "CardTable.h"
using namespace std;

int main() {
    CardTable card_table;
    card_table.add_card("Ad");
    card_table.add_card("2d");
    card_table.add_card("3d");
    card_table.add_card("4d");
    card_table.add_card("5d");
    card_table.add_card("Tc");
    card_table.add_card("Jc");
    cout << card_table.isStraightFlush() << endl;
}
