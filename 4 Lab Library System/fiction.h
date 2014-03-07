//------------------------------------------------------------------
//Fiction class represents fiction books
//includes:
//--Fiction objects contain all information necessary for identification
//--comparison operators that are necessary for BST
//--Parent class of fiction is nonperiodical
//Assumptions:
//--Assumes correct input for book information
//-----------------------------------------------------------------

#ifndef FICTION_H
#define FICTION_H

#include "book.h"
#include <fstream>


class Fiction : public Book{

public:
    //default constructor
	Fiction();
	
    //constructor with parameters for author, title, year
    Fiction(string title,  string author, int year);
	
    //overloaded comparison operators
    virtual bool operator<(const Item&) const;
    
     virtual bool operator>(const Item&) const;
    
    virtual bool operator== (const Item&) const;

     virtual bool operator!=(const Item&) const;
	
    //create an item
    virtual Item* create();
    
    virtual void initialize(istream&);

    virtual void initializePartial(istream&);
    
    virtual void print()const;
	
};

#endif
