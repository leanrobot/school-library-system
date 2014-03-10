//-----------------------------------------------------------------------------
// BOOK.H
// Book class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Book class: is an abstract class that defines a book object
// -- it is a parent class of Fiction and Youth classes
// -- it is child class of Item class
// Includes following features:
// -- Get and set author of the book
// -- Pure virtual methods for comparing two objects (==, !=, >, <)
// -- Pure virtual method for creating an object
// -- Pure virtual methods for initializing the book object which are
//    implementd in each child class
// -- Pure virtual method for printing information about the given type of the
//    book which is implemented in each child class.
// -- Pure virtual method for printing information about the book object in
//    user's history
// Assumptions:
// -- Assumes that valid input is given for datamembers
//-----------------------------------------------------------------------------

#ifndef BOOK_H
#define BOOK_H
#include "item.h"

using namespace std;

class Book : public Item{

public:
    // getAuthor
    // Returns the author of the book
    string getAuthor()const;
    
    // setAuthor
    // Set the new author for the given book
    void setAuthor(string);
    
    // Overloaded less than operator
    // Pure virtul method which will be implemented by child classes
    // to determine if given object is less than the other given object
    virtual bool operator< (const Item&)const = 0;
    
    // Overloaded greater than operator
    // Pure virtul method which will be implemented by child class
    // to determine if given object is greater than the other given object
    virtual bool operator> (const Item&)const = 0 ;
    
    // Overloaded equal operator
    // Pure virtul method which will be implemented by child classes
    // to determine if two given objects are equal
    virtual bool operator== (const Item&)const = 0;
    
    // Overloaded not equal operator
    // Pure virtul method which will be implemented by child classes
    // to determine if two given objects are not equal
    virtual bool operator!= (const Item&)const = 0 ;

    // create
    // Pure virtul method which will be implemented by child classes
    // to create a given object
    virtual Item* create() = 0;
    
    // initialize
    // Pure virtual method which will implemented by child classes
    // to initialized object when new object is added to the
    // library
    virtual void initialize(istream&) = 0;
    
    // initialize partial
    // Pure virtual method which will implemented by child classes
    // to initialized object to perform given transaction on it
    virtual void initializePartial(istream&) = 0;
	
    // print
    // Pure virtual method which will be implemented by child classes
    // to print information about the object
    virtual void print()const = 0;
    
    // display
    // Pure wirtual method which will be implemented by child classes
    // to print information about the object which is used in the
    // print method in the history transaction method
    virtual void display()const = 0;
   

protected:
    // Default Constructor
    Book();
    
    // Author of the book
    string author;
};

#endif
