//-----------------------------------------------------------------------------
// FICTION.H
// Fiction class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Fiction class: a class to represent the fiction objetcs. It is a child class
// of Book class. Includes following features:
// -- Compare operators (==, !=, >, <) to compare two fiction objects
// -- Create fiction object
// -- Initialized the fiction object
// -- Print the information about the fiction object
// -- Print the header
// -- Print information about the fiction object in user's history
// Assumptions:
// --Assumes correct and valid input from user for datamembers
//-----------------------------------------------------------------------------

#ifndef FICTION_H
#define FICTION_H

#include "book.h"
#include <fstream>


class Fiction : public Book{
    
public:
    // Default constructor
	Fiction();
    
    // Overloaded less than operator
    // Determine if this fiction object is less than the other fiction object
    virtual bool operator<(const Item&) const;
    
    // Overloaded greater than operator
    // Determine if this fiction object is greater than the other fiction object
    virtual bool operator>(const Item&) const;
    
    // Overloaded equal operator
    // Determine if two fiction objects are equal
    virtual bool operator== (const Item&) const;
    
    // Overloaded not equal operator
    // Determine if two fiction objects are not equal
    virtual bool operator!=(const Item&) const;
	
    // creat
    // Create fiction object
    virtual Item* create();
    
    // initialize
    // Initialized fiction object when new fiction oject is added to the
    // library
    virtual void initialize(istream&);
    
    // initialize partial
    // Initialized object fiction to perform given transaction on it
    virtual void initializePartial(istream&);
    
    // print
    // Print information about the fiction object
    virtual void print()const;
    
    // printHeader
    // Print header for the print method
    virtual void printHeader() const;
    
    // display
    // Print information about the fiction object which is used in the
    // print method in the history transaction method
    virtual void display()const;
};

#endif
