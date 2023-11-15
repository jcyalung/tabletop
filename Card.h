//
// Created by jcyal on 11/13/2023.
//
#include "supplement.h"
#ifndef TABLETOP_CARD_H
#define TABLETOP_CARD_H


class Card {
public:
    Card(); // test
    Card(string value, string suit);
    string to_string() const;
    string get_value();
    string get_suit();
    bool is_flipped() const;
    void flip();
private:
    bool flipped = false;
    string value;
    string suit;
};


#endif //TABLETOP_CARD_H
