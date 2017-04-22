//
//  main.cpp
//  project3
//
//  Created by Chris Becker on 4/11/17.
//  Copyright © 2017 Chris Becker. All rights reserved.
//

#include <iomanip>
#include <iostream> //input output stream
#include <fstream> //file stream (input and output)
#include "card.h"
#include "book.h"


using namespace std;



int main() {

    Card cards[20];
    int numCards = 0;
    
    cout<< "Opening cards.txt...";
    //setting up file pointer called cardInput
    ifstream cardInput("cards.txt"); // if not foudn its a null pointer or 0 of false
    //tests if the file is there
    if(!cardInput){
        cout<< "File not found! " <<endl
            << "cards.txt cannot be found. ";
        system("pause");
        exit(1);
    }
    
    cout<<"Reading File...";
    
    //read next line of file
    char name[20];
    char phone[20];
    int cardID = 0;
    char junk[10];
    
    cardInput.getline(name, 19, ','); //comma is a delimiter
   
    
    while(cardInput){
        
        cardInput.getline(junk, 5, ' ');//skips the space
        cardInput.getline(phone, 15, ','); //reads the phone number
        cardInput.getline(junk, 5, ' ');
        cardInput >> cardID;
        cardInput.getline(junk, 5, '\n');
        
        //create the new card
        cards[numCards] = Card(name, phone, cardID);
        
        cardInput.getline(name, 19, ',');
        
        numCards += 1;
    }
    
    cout << "Cards file read.\n";
    //create a card and store it in the array of cards
    
    
}


void ShowMenu(){
    cout<<" 1. Show all library cards" <<endl;
    
}



