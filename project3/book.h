//
//  book.h
//  project3
//
//  Created by Chris Becker on 4/11/17.
//  Copyright © 2017 Chris Becker. All rights reserved.
//

#ifndef bookHeader_h
#define bookHeader_h

#include <iostream>

using namespace std;


#define TITLE_SIZE 30
#define AUTHOR_SIZE 10

class Book {

private:
    
    char _title[TITLE_SIZE];
    char _author[AUTHOR_SIZE];
    int _bookID;
    int _cardID;
    
public:
    
    Book(); //Default constructor
    Book(char title[], char author[], int bookID, int cardID);
   
    int getCardID();
    void setCardID(int cardID);
    
    void printTitle();
    void printAuthor();
    
    void print();
};

#endif /* book_h */
