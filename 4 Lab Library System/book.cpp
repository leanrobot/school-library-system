//-----------------------------------------------------------------------------
// BOOK.CPP
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
#include "book.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Book class.
 ----------------------------------------------------------------------------*/
Book:: Book(): Item(){
}

/*---------------------------------------------------------------------------
 ===== getAuthor
 Descripton: Retrieve the author of the book's
 Pre:
 Post: Returns the author of the book
 ----------------------------------------------------------------------------*/
string Book:: getAuthor()const {
    return author;
}

/*---------------------------------------------------------------------------
 ===== setAuthor
 Descripton: Set up a new author for the book
 ----------------------------------------------------------------------------*/
void Book:: setAuthor(string newAuthor){
    this->author = newAuthor;
}
