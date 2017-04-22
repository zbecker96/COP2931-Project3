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

Book::Book(){
    title[0] = '\0'; //nullifies character array to initialize it
    author[0] = '\0';
    bookID = 0;
    cardID = 0;
}

Book::Book(char t[], char a[], int bID, int cID){
    bookID = bID;
    cardID = cID;
    strcpy(title, t);
    strcpy(author, a);
}

int Book::getCardID(){
    return cardID;
}

void Book::setCardID(int cID){
    cardID = cID;
}

void Book::printTitle(){
    cout<< title;
}

void Book::printAuthor(){
    cout<<"Written by: " <<author;
}

void Book::print(){
    cout<< bookID << ":" <<endl
        << title << endl
        <<author <<endl
        <<((cardID==0 )? "not Checked out" : "checked out to card " + to_string(cardID));
}

