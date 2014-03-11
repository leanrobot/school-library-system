#include "book.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Book class.
 Pre:
 Post:
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
 Pre:
 Post:
 ----------------------------------------------------------------------------*/
void Book:: setAuthor(string newAuthor){
    this->author = newAuthor;
}
