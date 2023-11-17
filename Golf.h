//
// Created by jcyal on 11/13/2023.
//
#include "Deck.h"
#ifndef TABLETOP_GOLF_H
#define TABLETOP_GOLF_H


class Golf : public Deck {
public:
    Golf();
    Golf(int r, int c);
    void display_board();
    void check_cols();
    void draw_card();
    void swap(int row_ind, int col_ind);
    void reveal_card();
    void change_turn();
    bool check_hidden_remaining() const;
    void check_score();
private:
    int current_turn = 1;
    int r1 = 2, c1 = 3;
    int r2 = 2, c2 = 3;
    int player1_score = 0;
    int player2_score = 0;
    int player1_flipped, player2_flipped;
    bool turn = true;
    vector<vector<Card>> board1;
    vector<vector<Card>> board2;
    stack<Card> remaining_cards;
    stack<Card> pool;

};


#endif //TABLETOP_GOLF_H
