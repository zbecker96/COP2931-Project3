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

class Book{

private:
    
    char title[30];
    char author[10];
    int bookID;
    int cardID;
    
public:
    
    Book(); //Default constructor
    Book(char t[], char a[], int bID, int cID);
   
    int getCardID();
    void setCardID(int cID);
    
    void printTitle();
    void printAuthor();
    
    void print();
};

#endif /* book_h */
