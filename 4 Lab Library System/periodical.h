//----------------------------------------------------------------
//Periodical is the class for creating objects that are periodicals
//Includes:
//--Parent class is book.
//--Keeps track of all relevant information for a periodical
//Assumptions:
//--assumes valid and correct input for data members
//----------------------------------------------------------------

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "book.h"
#include <fstream>

class Periodical : public Item{
    
public:
    
    //default constructor
    Periodical();
    
    //constructor with parameters are the title, month, and year
    Periodical(string, int, int);
    
    //retrieve the month of the book's publishing
    int getMonth() const;
    
    //set the month of the book's publishing parameter is month
    void setMonth(int);
    
    //operators for item comparison
    virtual bool operator<(const Item&) const;
    
    virtual bool operator>(const Item&) const;

    
    virtual bool operator== (const Item&) const;
    
     virtual bool operator!= (const Item&) const;
   
    //create item
    virtual Item* create(istream&);
    
    virtual void print () const;
	
    
private:
    
    //month of publication
    int month;
};

#endif
