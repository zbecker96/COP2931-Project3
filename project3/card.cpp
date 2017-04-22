//
//  card.cpp
//  project3
//
//  Created by Chris Becker on 4/11/17.
//  Copyright © 2017 Chris Becker. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "card.h"

using namespace std;

Card::Card() {
    _name[0] ='\0';
    _phone[0] = '\0';
    _cardID = 0;
    _bookID = 0;
    
}

Card::Card(char name[], char phone[], int cardID) {
    strncpy(_name, name, NAME_SIZE); //dad said its more secure of a coding pratice to use strncpy than strcpy works the same tho.
    strncpy(_phone, phone, PHONE_SIZE);
    _cardID = cardID;
}

/**
 Get Book ID

 @return Book ID
 */

int Card::getBookID() {
    return _bookID;
}

/**
 Set Book ID

 @param bookID Book ID
 */

void Card::setBookID(int bookID) {
    _bookID = bookID;
}

/**
 Print Card
 */
void Card::print() {
    cout << _cardID << ": " << _name << " " << _phone << endl;
}
