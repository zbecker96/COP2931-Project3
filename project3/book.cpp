//
//  book.cpp
//  project3
//
//  Created by Chris Becker on 4/11/17.
//  Copyright © 2017 Chris Becker. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "book.h"

using namespace std;

Book::Book() {
    _title[0] = '\0'; //nullifies character array to initialize it
    _author[0] = '\0';
    _bookID = 0;
    _cardID = 0;
}

Book::Book(char title[], char author[], int bookID, int cardID) {
    _bookID = bookID;
    _cardID = cardID;
    strncpy(_title, title, TITLE_SIZE);
    strncpy(_author, author, AUTHOR_SIZE);
}

/**
 Get Card ID

 @return Card ID
 */
int Book::getCardID() {
    return _cardID;
}

/**
 Set Card ID

 @param cardID Card ID
 */
void Book::setCardID(int cardID) {
    _cardID = cardID;
}

/**
 Print Title
 */
void Book::printTitle() {
    cout << _title;
}

/**
 Print Author
 */
void Book::printAuthor() {
    cout << "Written by: " << _author;
}

/**
 Print Book Information
 */
void Book::print() {
    cout << _bookID << ":" << endl
         << _title  << endl
         << _author << endl
         << ((_cardID == 0 ) ? "not Checked out" : "checked out to card " + to_string(_cardID));
}

