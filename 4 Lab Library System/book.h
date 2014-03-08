//----------------------------------------------------
//Book class: a class that defines a book object
//--Parent class of periodical and nonperiodical
//--Child class of item
//Includes:
//--creats book objects will all datamembers that are common to all books
//--comparison operators
//--get and set datamembers
//Assumptions:
//--Assumes that valid input is given for datamembers
//----------------------------------------------------

#ifndef BOOK_H
#define BOOK_H
#include "item.h"

using namespace std;


class Book : public Item{

public:

    //overloaded comparison operators
    virtual bool operator<(const Item&) const = 0;
    
    virtual bool operator>(const Item&) const = 0 ;
    
    virtual bool operator==(const Item&) const = 0;
    
    virtual bool operator!= (const Item&) const = 0 ;

    //create an item
    virtual Item* create() = 0;
    
    
    
    string getAuthor()const;
    
    void setAuthor(string);
	
    virtual void print()const = 0;
    
    virtual void initialize(istream&) = 0;
    
    virtual void initializePartial(istream&) = 0;

protected:
    
    Book();
    
    //default constructor
   // Book(char itemType, string title, string author, int year);
    
    string author;
};

#endif
