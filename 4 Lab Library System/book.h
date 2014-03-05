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
#include <string>
using namespace std;


class Book : public Item{

public:

    //default constructor
	//Book();

    //constructor with parameters for title and year
   // Book(string, int);

    
    //overloaded comparison operators
    virtual bool operator<(const Item&) const = 0;
    
    virtual bool operator== (const Item&) const = 0 ;

    //create an item
    virtual Item* create();
    
    string getAuthor()const;
    
    void setAuthor(string);
	


private:

    string author;
};

#endif
