//---------------------------------------------------------------
//Youth represents a book of the genre youth
//Includes:
//--Youth contains functions and data necessary for keeping track
//--of information related to the book (title author etc.)
//--Youth is a child class of non-periodical
//Assumptions:
//--Assumes correct and valid input from user for datamembers
//---------------------------------------------------------------

#ifndef YOUTH_H
#define YOUTH_H

#include "book.h"
#include <fstream>


class Youth : public Book{
    
public:
	//default constructor
    Youth();
	
    //constructor with parameters for author, title, year
    //Youth(string, string, int);
	
    //overloaded comparison operators
    virtual bool operator<(const Item&) const;
    
    virtual bool operator>(const Item&) const;

	
    virtual bool operator== (const Item&)const;
    
    virtual bool operator!=(const Item&) const;

    
    //create an item
    virtual Item* create();
    virtual void initialize(istream& infile);
    virtual void initializePartial(istream& infile);
    
    
    
    virtual void print ()const;
    virtual void display()const;
    virtual void printHeader() const;
	
};

#endif
