//
//  card.h
//  project3
//
//  Created by Chris Becker on 4/11/17.
//  Copyright © 2017 Chris Becker. All rights reserved.
//

#ifndef cardHeader_h
#define cardHeader_h

#include <iostream>
using namespace std;

#define NAME_SIZE 20
#define PHONE_SIZE 20

class Card{
    
private:
    
    char _name[NAME_SIZE];
    char _phone[PHONE_SIZE];
    int _cardID;
    int _bookID;
    
public:
    
    Card(); // default constructor
    Card(char name[], char phone[], int cardID );
    
    void setBookID(int bookID);
    int getBookID();
    int getCardID();
    
    void print();
    
};

#endif /* card_h */
