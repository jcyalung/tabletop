//
// Created by jcyal on 11/13/2023.
//

#include "Golf.h"

/**
 * default size
 * x = 2
 * y = 3
 */
Golf::Golf() {
    // shuffle the deck
    shuffle();

    // index for deck
    int index = 0;

    // for every row, place a new vector
    for(int rows = 0; rows < r; rows++) {
        board1.emplace_back();
        board2.emplace_back();
    }
    // now store cards
    for(int row = 0; row < r; row++) {
        for(int col = 0; col < c; col++) {
            board1[row].push_back(deck[++index]);
            board2[row].push_back(deck[++index]);
        }
    }

    // rest of remaining cards go into the stack
    for(int i = index; i < BASIC_DECK_SIZE; i++) {
        remaining_cards.push(deck[i]);
    }

    // pool always starts with one card
    pool.push(remaining_cards.top()); remaining_cards.pop();
}

/**
 * construct golf game with set parameters
 * rows are in between 1-4 inclusive, since you can only have 4 of the same value card
 * columns can be of any size
 * @param r
 * @param c
 */
Golf::Golf(int r, int c) {
    // check rows input is greater than 4 or less than or equal to 1
    if(r > 4 || r <= 1) {
        cout << "Rows must be in between 1 to 4." << endl
             << "Number of rows is now set to 2." << endl;
        r = 2;
    }
    // check if columns input is less than 1
    // set to default settings
    if(c <= 1) {
        cout << "Columns must be greater than 1." << endl
             << "Number of columns is now set to 3." << endl;
        c = 3;
    }
    // check if the matrix size is greater than a third the basic deck size; if so set to regular settings
    // could be changed so that the deck is bigger
    if(r * c > BASIC_DECK_SIZE / 3) {
        r = 2;
        c = 3;
        cout << "The resulting matrix is too big." << endl
             << "Using default settings." << endl;
    }

    // set num rows and num cols
    this->r = r;
    this->c = c;

    // shuffle the deck initially
    shuffle();
    int index = 0; // index for current deck

    // for every row, place a new vector
    for(int rows = 0; rows < r; rows++) {
        board1.emplace_back();
        board2.emplace_back();
    }

    // now store cards
    for(int row = 0; row < r; row++) {
        for(int col = 0; col < c; col++) {
            board1[row].push_back(deck[++index]);
            board2[row].push_back(deck[++index]);
        }
    }

    // rest of remaining cards go into the stack
    for(int i = index; i < BASIC_DECK_SIZE; i++) {
        remaining_cards.push(deck[i]);
    }

    // pool starts with one card
    pool.push(remaining_cards.top()); remaining_cards.pop();
    pool.top().flip();


}

/**
 * check columns to see if column has same value
 * if so,
 * @param turn
 */
void Golf::check_cols() {
    string value;
    bool same;
    // if player 1 turn, check player 1 board
    if(turn) {
        // iterate through columns
        for(int col = 0; col < board1[0].size(); col++) {

            // all elements are same at start
            same = true;

            // iterating through rows
            for(int row = 0; row < board1.size(); row++) {

                // if row is at the top, set the value to the top value
                if(row == 0) {
                    value = board1[row][col].get_value();
                    if(!board1[row][col].is_flipped()) { same = false; }
                }

                // otherwise, check if the value at index does not equal value
                else {
                    // if so, values are not the same
                    if(board1[row][col].get_value() != value || !board1[row][col].is_flipped()) { same = false; }
                }
            }
            // if all values are the same, erase the column
            if(same) {
                for(int row = 0; row < board1.size(); row++) {
                    board1[row].erase(board1[row].begin() + col);
                }
            }
        }
    }
    // otherwise check player 2 board
    else {
        // iterate through columns
        for(int col = 0; col < board2[0].size(); col++) {

            // all elements are same at start
            same = true;

            // iterating through rows
            for(int row = 0; row < board2.size(); row++) {

                // if row is at the top, set the value to the top value
                if(row == 0) {
                    value = board2[row][col].get_value();
                    if(!board2[row][col].is_flipped()) { same = false; }
                }

                // otherwise, check if the value at index does not equal value
                else {
                    // if so, values are not the same
                    if(board2[row][col].get_value() != value || !board2[row][col].is_flipped()) { same = false; }
                }
            }
            // if all values are the same, erase the column
            if(same) {
                for(int row = 0; row < board2.size(); row++) {
                    board2[row].erase(board2[row].begin() + col);
                }
            }
        }
    }
}

/**
 * displays the board
 */
void Golf::display_board() {
    cout << setw(30);
    for(int row = 0; row < board1.size(); row++) {
        for(int col = 0; col < board1[0].size(); col++) {
            cout << board1[row][col].to_string() << setw(30);
        }
        cout << endl << endl;
    }
    cout << setfill('-') << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(30);
    for(int row = 0; row < board2.size(); row++) {
        for(int col = 0; col < board2[0].size(); col++) {
            cout << board2[row][col].to_string() << setw(30);
        }
        cout << endl << endl;
    }
    cout << "Pool: " << pool.top().to_string() << endl;
    cout << "Remaining cards: " << remaining_cards.size() << endl;
    if(turn) {
        cout << "Current turn: Player 1" << endl;
    }
    else {
        cout << "Current turn: Player 2" << endl;
    }

}

/**
 * draw a card
 */
void Golf::draw_card() {
    if(!remaining_cards.empty()) {
        pool.push(remaining_cards.top()); remaining_cards.pop();
        pool.top().flip();
    }
    char userInput;
    do {
        cout << "The top of the pool is now: " << pool.top().to_string() << endl;
        cout << "Would you like to swap? "
                "\ny. yes"
                "\nn. no" << endl;
        cin >> userInput;
        if(userInput != 'y' && userInput != 'n') {
            cout << "Invalid input. Try again." << endl;
        }
    } while(userInput != 'y' && userInput != 'n');
    if(userInput == 'y') {
        int row_ind, col_ind;
        cout << "Enter the row index and col index, followed by a space: " << endl;
        cin >> row_ind >> col_ind;
        this->swap(row_ind,col_ind);
    }
    if(userInput == 'n') {
        return;
    }
}

void Golf::swap(int row_ind, int col_ind) {
    Card temp = pool.top();
    pool.pop();
    if(turn) {
        pool.push(board1[row_ind][col_ind]);
        board1[row_ind][col_ind] = temp;
    }
    else {
        pool.push(board2[row_ind][col_ind]);
        board2[row_ind][col_ind] = temp;
    }
    if(!pool.top().is_flipped()) {
        pool.top().flip();
    }
}

void Golf::reveal_card() {
    int row_int, col_int;
    char row_ind, col_ind;
    do {
        cout << "Enter a row index and a column index to flip, followed by a space: " << endl;
        cin >> row_ind;
        cin >> col_ind;
        row_int = row_ind - 48;
        col_int = col_ind - 48;
        if(row_int > r || row_int < 0 || col_int > c || col_int < 0) {
            cout << "Invalid input. Try again." << endl;
        }
    } while(row_int > r || row_int < 0 || col_int > c || col_int < 0);
    // if player one's turn
    if(turn) {
        if(board1[row_int][col_int].is_flipped()) {
            cout << "Already flipped. " << endl;
            reveal_card();
        }
        else {
            board1[row_int][col_int].flip();
        }
    }
    else {
        if(board2[row_int][col_int].is_flipped()) {
            cout << "Already flipped. " << endl;
            reveal_card();
        }
        else {
            board2[row_int][col_int].flip();
        }
    }
}

void Golf::change_turn() {
    turn = !turn;
    if(turn) {
        cout << "It is now player 1's turn." << endl;
    }
    else {
        cout << "It is now player 2's turn." << endl;
    }
}

bool Golf::check_hidden_remaining() const {
    int player1_hiddens = board1.size(), player2_hiddens = board2.size();
    if(player1_hiddens == 0 || player2_hiddens == 0) {
        return true;
    }
    else {
        player1_hiddens *= board1[0].size();
        player2_hiddens *= board2[0].size();
        cout << "Max hidden cards for player 1: " << player1_hiddens << endl;
        cout << "Max hidden cards for player 2: " << player2_hiddens << endl;
        for(int x = 0; x < board1.size(); x++) {
            for(int y = 0; y < board1[0].size(); y++) {
                player1_hiddens -= board1[x][y].is_flipped();
            }
        }
        for(int x = 0; x < board2.size(); x++) {
            for(int y = 0; y < board2[0].size(); y++) {
                player2_hiddens -= board2[x][y].is_flipped();
            }
        }
        cout << "Hidden cards for player 1: " << player1_hiddens << endl;
        cout << "Hidden cards for player 2: " << player2_hiddens << endl;
        return player1_hiddens != 0 || player2_hiddens != 0;
    }
}
