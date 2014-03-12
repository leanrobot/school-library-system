//-----------------------------------------------------------------------------
// PERIODICAL.H
// Periodical class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Periodical class: a class to represent the periodical objetcs. It is a child
// class of Item class. Includes following features:
// -- Get the month when the book was published
// -- Set a new publishing month for the book
// -- Compare operators (==, !=, >, <)to compare two periodicals
// -- Create periodical object
// -- Initialized the periodical object
// -- Print the information about the periodical object
// -- Print the header
// -- Print information about the periodical object in user's history
// Assumptions:
// --assumes valid and correct input for data members
//-----------------------------------------------------------------------------

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "book.h"
#include <fstream>

class Periodical : public Item{
    
public:
    
    // Default constructor
    Periodical();
    
    // getMonth
    // Retrieve the month of the book's publishing
    int getMonth()const;
    
    // setMonth
    // Set the month of the book's publishing parameter
    void setMonth(int newMonth);
    
    // Overloaded less than operator
    // Determine if this periodical object is less than the other periodical
    // object
    virtual bool operator< (const Item& otherItem)const;
    
    // Overloaded greater than operator
    // Determine if this periodical object is greater than the other
    // periodical object
    virtual bool operator> (const Item& otherItem)const;
    
    // Overloaded equal operator
    // Determine if two periodical objects are equal
    virtual bool operator== (const Item& otherItem)const;
    
    // Overloaded not equal operator
    // Determine if two periodical objects are not equal
    virtual bool operator!= (const Item& otherItem)const;
    
    // create
    // create periodical object
    virtual Item* create();
    
    // initialize
    // Initialized periodical object when new periodical is added to the
    // library
    virtual void initialize(istream& infile);
    
    // initialize partial
    // Initialized object peridical to perform given transaction on it
    virtual void initializePartial(istream& infile);
    
    // print
    // Print information about the periodical object
    virtual void print ()const;
    
    // printHeader
    // Print header for the print method
    virtual void printHeader()const;
    
    // display
    // Print information about the periodical objects which are used
    // in the print method in the history transaction method
    virtual void display()const;
    
private:
    
    //month of the publication
    int month;
};

#endif /* PERIODICAL_H */
