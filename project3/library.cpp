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
#include <limits>
#include "library.h"


using namespace std;

#define JUNK_SIZE 40

Library::Library() {
}

/**
 Run the Library application
 */
void Library::run() {

    if (!readCardFile() || !readBookFile()) {
        exit(1);
    }

    int choice = showMenu();
    while (choice != 6) {
        switch (choice) {
            case 1:
                showAllLibraryCards();
                break;
            case 2:
                showAllBooks();
                break;
            case 3:
                checkOutBook();
                break;
            case 4:
                checkInBook();
                break;
            case 5:
                createNewLibraryCard();
                break;
            default:
                break;
        }
        choice = showMenu();
    }
}

/**
 Read the card.txt file

 @return true if succeeded
 */
bool Library::readCardFile() {
    cout<< "Opening cards.txt" << endl;
    //setting up file pointer called cardInput
    ifstream cardInput("cards.txt"); // if not foudn its a null pointer or 0 of false
    //tests if the file is there
    if(!cardInput){
        cout<< "File not found! " <<endl
        << "cards.txt cannot be found. ";
        system("pause");
        return false;
    }
    
    cout<<"Reading File...";
    
    //read next line of file
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    int cardID = 0;
    char junk[JUNK_SIZE];
    _numCards = 0;
    
    cardInput.getline(name, 19, ','); //comma is a delimiter
    
    while(cardInput){
        
        cardInput.getline(junk, JUNK_SIZE, ' ');//skips the space
        cardInput.getline(phone, PHONE_SIZE, ','); //reads the phone number
        cardInput.getline(junk, JUNK_SIZE, ' ');
        cardInput >> cardID;
        cardInput.getline(junk, JUNK_SIZE, '\n');
        
        //create a card and store it in the array of cards
        _cards[_numCards] = Card(name, phone, cardID);
        
        cardInput.getline(name, NAME_SIZE, ',');
        //move to the next card
        _numCards += 1;
    }
    
    cout << "done." << endl;
    return true;
}

/**
 Read the books.txt file

 @return true if succeeded
 */
bool Library::readBookFile() {
    cout << "Opening Books.txt" << endl;
    ifstream bookInput("books.txt");
    if(!bookInput) {
        cout << "File not found! " << endl
        << "books.txt is unavailable check file path." ;
        system("pause");
        return false;
    }
    
    cout<< "Reading books.txt...";
    
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    int bookID = 0;
    char junk[JUNK_SIZE];
    _numBooks = 0;
    
    bookInput.getline(title,TITLE_SIZE,',');
    
    while(bookInput) {
        
        bookInput.getline(junk, JUNK_SIZE, ' ');//skips the space
        bookInput.getline(author, AUTHOR_SIZE, ',');
        bookInput.getline(junk, JUNK_SIZE, ' ');
        bookInput >> bookID;
        bookInput.getline(junk, JUNK_SIZE, '\n');
        
        _books[_numBooks] = Book(title, author, bookID);
        
        bookInput.getline(title,TITLE_SIZE,',');
        
        _numBooks += 1;
        
    }
    
    cout << "done." << endl;
    return true;
}

/**
 Show the Menu

 @return The command number from 1-6
 */
int Library::showMenu(){
    int choice = 0;
    while (choice < 1 || choice > 6){
        cout << endl << "Menu: " << endl;
        cout << "----------------------------" << endl;
        cout << "1. Show all library cards.  " << endl;
        cout << "2. Show all books           " << endl;
        cout << "3. Check out a book         " << endl;
        cout << "4. Check in a book          " << endl;
        cout << "5. Create a new library card" << endl;
        cout << "6. Exit the system          " << endl;
        cin >> choice;
        if (cin.fail()) {
            choice = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    return choice;
}

void Library::showAllLibraryCards() {
    cout << endl << "Cards: " << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < _numCards; i++) {
        _cards[i].print();
    }
}

void Library::showAllBooks() {
    cout << endl << "Books: " << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < _numBooks; i++) {
        _books[i].print();
    }
}

void Library::checkOutBook() {
    
}

void Library::checkInBook() {
    
}

void Library::createNewLibraryCard() {
    
}
