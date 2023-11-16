//
// Created by jcyal on 11/13/2023.
//
#include "Card.h"
#ifndef TABLETOP_DECK_H
#define TABLETOP_DECK_H


class Deck {
public:
    Deck();
    void shuffle();
    void print_deck();
protected:
    Card deck[BASIC_DECK_SIZE];
    unordered_map<string, int> card_value = {
            {"Ace", 1},
            {"Two", 2},
            {"Three", 3},
            {"Four", 4},
            {"Five", 5},
            {"Six", 6},
            {"Seven", 7},
            {"Eight", 8},
            {"Nine", 9},
            {"Ten", 10},
            {"Jack", 11},
            {"Queen", 12},
            {"King", 13}
    };
    vector<Card> extended_deck;
};


#endif //TABLETOP_DECK_H
