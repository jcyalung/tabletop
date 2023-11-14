//
// Created by jcyal on 11/13/2023.
//

#include "Deck.h"

Deck::Deck() {
 for(int spades = 0; spades < 13; spades++) {
     deck[spades] = Card(VALUES[spades], "Spades");
 }
 for(int diamonds = 13; diamonds < 26; diamonds++) {
     deck[diamonds] = Card(VALUES[diamonds - 13], "Diamonds");
 }
 for(int clubs = 26; clubs < 39; clubs++) {
     deck[clubs] = Card(VALUES[clubs - 26], "Clubs");
 }
 for(int hearts = 39; hearts < BASIC_DECK_SIZE; hearts++) {
     deck[hearts] = Card(VALUES[hearts - 39], "Hearts");
 }
}

void Deck::shuffle() {
    // initialize random device
    random_device rd;

    // initialize a random number generator
    mt19937 g(rd());

    // shuffle deck here to make sure that it is always random
    std::shuffle(&deck[0], &deck[BASIC_DECK_SIZE], g);
}

void Deck::print_deck() {
    for(Card& card: deck) {
        cout << card.to_string() << endl;
    }
}
