//-----------------------------------------------------------------------------
// YOUTH.H
// Youth class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Youth class: a class to represent the youth objetcs. It is a child class
// of Book class. Includes following features:
// -- Compare operators (==, !=, >, <)to compare two youths
// -- Create youth object
// -- Initialized the youth object
// -- Print the information about the youth object
// -- Print the header
// -- Print information about the youth object in user's history
// Assumptions:
// --Assumes correct and valid input from user for datamembers
//-----------------------------------------------------------------------------

#ifndef YOUTH_H
#define YOUTH_H

#include "book.h"
#include <fstream>

class Youth : public Book{
    
public:
	
    // Default constructor
    Youth();
	
    
    // Overloaded less than operator
    // Determine if this youth object is less than the other youth object
    virtual bool operator< (const Item& otherItem)const;
    
    // Overloaded greater than operator
    // Determine if this youth object is greater than the other youth object
    virtual bool operator> (const Item& otherItem)const;

    // Overloaded equal operator
    // Determine if two youth objects are equal
    virtual bool operator== (const Item& otherItem)const;
    
    // Overloaded not equal operator
    // Determine if two youth objects are not equal
    virtual bool operator!= (const Item& otherItem)const;
    
    //create
    // Create youth object
    virtual Item* create();
    
    // initialize
    // Initialized youth object when new youth oject is added to the
    // library
    virtual void initialize(istream& infile);
    
    // initialize partial
    // Initialized object youth to perform given transaction on it
    virtual void initializePartial(istream& infile);
    
    // print
    // Print information about the youth object
    virtual void print()const;
    
    // printHeader
    // Print header for the print method
    virtual void printHeader() const;
    
    // display
    // Print information about the youth object which is used in the
    // print method in the history transaction method
    virtual void display()const;
	
};

#endif /*YOUTH*/

