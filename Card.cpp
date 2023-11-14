//
// Created by jcyal on 11/13/2023.
//

#include "Card.h"

Card::Card() {}

Card::Card(string value, string suit) {
    this->value = value;
    this->suit = suit;
}

string Card::to_string() const {
    return value + " of " + suit;
}

string Card::get_value() {
    return value;
}

string Card::get_suit() {
    return suit;
}
