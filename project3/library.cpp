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
#include <string>
#include "library.h"


using namespace std;

#define JUNK_SIZE 40

//creates the library
Library::Library() {
}

/*
 
 Run the Library application
 
 */
void Library::run() {

    //catches a failure to read any file
    if (!readCardFile() || !readBookFile()) {
        exit(1);
    }

    //if the files are read it progresses on to
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
        cout << "————————————————————————————" << endl;
        cout << "1. Show all library cards.  " << endl;
        cout << "2. Show all books           " << endl;
        cout << "3. Check out a book         " << endl;
        cout << "4. Check in a book          " << endl;
        cout << "5. Create a new library card" << endl;
        cout << "6. Exit the system          " << endl;
        cout << "————————————————————————————" << endl;
        cout << "Enter a selection:          " << endl;
        
        
        cin.clear();
        
        // Read a single digit.
        // Note:  I had trouble validating the input as a single digit.  Googling turned up this suggested fix which appears working:
        // http://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input

        cin >> choice;
        if (cin.fail()) {
            choice = 0;
            //clears the input buffer or else if will run the loop however many numebr of characters you input lol
            cin.clear();
            cin.ignore(10000,'\n');//ignores a bunch of stuff, can use numeric_limits<streamsize>::max() instead of 10000
        }
    }
    return choice;
}


/*
 shows library cards
 
 
 */

void Library::showAllLibraryCards() {
    
    cout << endl << "Cards: " << endl;
    cout << "————————————————————————————" << endl;
    
    for (int i = 0; i < _numCards; i++) {
        _cards[i].print();
    }
    
    cout << "————————————————————————————" << endl;

}

/*
 
 Shows All Books in Library
 
 */

void Library::showAllBooks() {
    cout << endl << "Books: " << endl;
    cout << "————————————————————————————" << endl;
    
    for (int i = 0; i < _numBooks; i++) {
        _books[i].print();
    }
    
    cout << "————————————————————————————" << endl;

}


/*
 
 checks out book
 
 */

void Library::checkOutBook() {
    
    int bookN = 0; int cardN = 0;
    int card = 0; int book = 0;
    
    //get card id
    cout << "Enter the Card ID: " << endl;
    cin >> cardN;
    
    //search for it
    while( card < _numCards && cardN != _cards[card].getCardID()){
        card++;
    }
    
    //if not foudn return
    if(card == _numCards){
        cout << "Cards not found" << endl;
        return;
    }
    
    //if found do the yhave book?
    if(_cards[card].getBookID() != 0) {
        cout << "Must check in other book first" << endl;
        return;
    }
    
    //--------
    
    //get book id
    cout << "Enter the Book ID you wish to check out" << endl;
    cin >> bookN;
    
    while(book < _numBooks && bookN != _books[book].getBookID()){
        book++;
    }
    
    //search for book id
    if(book == _numBooks){
        cout << "Book not found " << endl;
        return;
    }

    
    //if found, checked out?
    
    if(_books[book].getCardID() != 0){
        cout << "book already checked out " << endl;
        return;
    }
    
    
    _cards[card].setBookID(bookN);
    
    _books[book].setCardID(cardN);
    
    
    
}

/*
 
 checks in a book
 
 */

void Library::checkInBook() {
    
    int bookN = 0; int cardN = 0;
    int card = 0; int book = 0;
    
    //get card id
    cout << "Enter the Card ID: " << endl;
    cin >> cardN;
    
    //search for it
    while( card < _numCards && cardN != _cards[card].getCardID()){
        card++;
    }
    
    //if not foudn return
    if(card == _numCards){
        cout << "Card not found" << endl;
        return;
    }
    
    //get book id
    cout << "Enter the Book ID you wish to check in" << endl;
    cin >> bookN;
    
    while(book < _numBooks && bookN != _books[book].getBookID()){
        book++;
    }
    
    //search for book id
    if(book == _numBooks){
        cout << "Book not found " << endl;
        return;
    }
    
    _cards[card].setBookID(0);
    
    _books[book].setCardID(0);
    
}

/*
 
 creates a new library card
 
 */

void Library::createNewLibraryCard() {
    
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    
    
    //clear input buffer
    cin.clear();
    cin.ignore(10000,'\n');//ignores a bunch of stuff, can use numeric_limits<streamsize>::max() instead of 10000
    

    cout << endl << "Please enter the card name:" << endl;
    cin.getline(name, NAME_SIZE);
    
    cout << endl << "Please enter the cards phone number:" << endl;
    cin >> phone;

  
    Card temp = Card(name, phone, _numCards);
    
    _cards[_numCards] = temp;
    
    _numCards++;
    
    
}
