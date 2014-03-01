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

#include "nonPeriodical.h"
#include <string>

class Youth : public NonPeriodical{

public:
	//default constructor
    Youth();
	
    //constructor with parameters for author, title, year
    Youth(string, string, int);
	
    //overloaded comparison operators
    virtual bool operator<(const Item&) const;
	
    //create an item
    virtual Item* create();
	
	//get description of a children book, like author, title, date
	virtual string getDescription() const;
};

#endif
