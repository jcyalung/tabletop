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
    if(flipped) {
        return value + " of " + suit;
    }
    else {
        return "?";
    }
}

string Card::get_value() {
    return value;
}

string Card::get_suit() {
    return suit;
}

bool Card::is_flipped() const {
    return flipped;
}

void Card::flip() {
    flipped = !flipped;
}
