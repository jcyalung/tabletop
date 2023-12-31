#include "Deck.h"
#include "Golf.h"
#include <iostream>

int main() {
    Golf test;
    char userInput;
    test.display_board();
    while(test.check_hidden_remaining()) {
        cout << "d. Draw card" << endl
             << "s. Swap card" << endl
             << "r. Reveal card" << endl;
        cin >> userInput;
        if(userInput == 'd') {
            test.draw_card();
        }
        if(userInput == 's') {
                int row_ind, col_ind;
                cout << "Enter the row index and col index, followed by a space: " << endl;
                cin >> row_ind >> col_ind;
                test.swap(row_ind,col_ind);
        }
        if(userInput == 'r') {
            test.reveal_card();
        }
        test.check_cols();
        test.change_turn();
        test.display_board();
    }
    test.display_board();
    test.check_score();
    return 0;
}
