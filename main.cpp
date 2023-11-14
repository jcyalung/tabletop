#include "Deck.h"
#include "Golf.h"
#include <iostream>

int main() {
    Golf test(3,1);
    char userInput;
    test.display_board();
    while(userInput != 'n') {
        cout << "d. Draw card" << endl
             << "s. Swap card" << endl;
        cin >> userInput;
        if(userInput == 'd') {
            test.draw_card();
        }
        if(userInput == 's') {
            int row_ind, col_ind;
            cout << "Enter the row index and col index, followed by a space: " << endl;
            cin >> row_ind >> col_ind;
            test.swap(row_ind,col_ind, true);
        }
        test.check_cols(true);
        test.display_board();
    }
    return 0;
}
