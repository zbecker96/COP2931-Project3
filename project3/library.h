//
//  library.h
//  project3
//
//  Created by Chris Becker on 4/22/17.
//  Copyright © 2017 Chris Becker. All rights reserved.
//

#ifndef library_h
#define library_h
#include "card.h"
#include "book.h"

#define MAX_BOOKS 20
#define MAX_CARDS 20

class Library {
    
private:
    
    Card _cards[MAX_CARDS];
    Book _books[MAX_BOOKS];
    
    int _numCards = 0;
    int _numBooks = 0;

    bool readCardFile();
    bool readBookFile();
    
    int showMenu();
    
    void showAllLibraryCards();
    void showAllBooks();
    void checkOutBook();
    void checkInBook();
    void createNewLibraryCard();
    
public:
    
    Library(); // default constructor
    
    void run();
};

#endif /* library_h */
