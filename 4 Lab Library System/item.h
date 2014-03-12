//-----------------------------------------------------------------------------
// ITEM.H
// Item class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Item class: is an abstract class that defines an item object
// -- it is a parent class of Book and Periodical classes
// Includes following features:
// -- Get and set methods for private data members
// -- Pure virtual methods for comparing two objects (==, !=, >, <)
// -- Pure virtual method for creating an item object which is implemented in
//    each child class
// -- Pure virtual methods for initializing the item object which are
//    implementd in each child class
// -- Pure virtual method for printing information about the given type of the
//    item which is implemented in each child class.
// -- Pure virtual method for printing information about the item object in
//     user's history
// Assumptions:
// -- Assumes that valid input is given for datamembers
//-----------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "hashable.h"
using namespace std;

class Item: public Hashable {

public:
	
	// Virtual destructor
	virtual ~Item();
    
    // getItemType
    // Returns the item type
    char getItemType()const;

    // setItemType
    // Set the itemtype
    void setItemType(char itemType);

    // getTotalCopies
    // Returns the number of copies of the item
    int getTotalCopies()const;
    
    // setTotalCopies
    // Set the number of total copies of item
    void setTotalCopies(int totalCopies);

    // getCheckOutCopies
    // Returns the number of check out copies of item
    int getCheckedOutCopies()const;
    
    // setCheckOutCopies
    // Set the number of check out copies
    void setCheckedOutCopies(int checkOutCopies);
    
    // getYear
    // Return the publication year of the item
    int getYear() const;
    
    // setYear
    // Set the publication year of the item
    void setYear(int newYear);
    
    // getTitle
    // Returns the title of the item
    string getTitle() const;
    
    // setTitle
    // Set the title of the item
    void setTitle(string newTitle);

    // Overloaded less than operator
    // Pure virtul method which will be implemented by child classes
    // to determine if given object is less than the other given object
    virtual bool operator< (const Item& otherItem)const = 0;
    
    // Overloaded greater than operator
    // Pure virtul method which will be implemented by child classes
    // to determine if given object is greater than the other given object
    virtual bool operator> (const Item& otherItem)const = 0;

    // Overloaded equal operator
    // Pure virtul method which will be implemented by child classes
    // to determine if two given objects are equal
    virtual bool operator== (const Item& otherItem)const = 0;
    
    // Overloaded not equal operator
    // Pure virtul method which will be implemented by child classes
    // to determine if two given objects are not equal
    virtual bool operator!= (const Item& otherItem)const = 0;
    
    // create
    // Pure virtul method which will be implemented by child classes
    // to create a given object
    virtual Item* create() = 0;
    
    // initialize
    // Pure virtual method which will implemented by child classes
    // to initialized object when new object is added to the
    // library
    virtual void initialize(istream&) = 0;
    
    // initialize partial
    // Pure virtual method which will implemented by child classes
    // to initialized object to perform given transaction on it
    virtual void initializePartial(istream&) = 0;

    // print
    // Pure virtual method which will be implemented by child classes
    // to print information about the object
    virtual void print() const = 0;
    
    // printHeader
    // Pure virtual method which will be implemented by child classes
    // to print header for the print method
    virtual void printHeader() const = 0;
    
    // display
    // Pure wirtual method which will be implemented by child classes
    // to print information about the object which is used in the
    // print method in the history transaction method
    virtual void display()const = 0;
    
    // hash
    // Return the item type
    char hash () const;
    
protected:
    
    // Default constructor
    Item();
    
    // Year of the publishing the item
    int year;
    
    // Title of the item
    string title;
    
    // Type of the item
    char itemType;
    
    // Format of the item (i.e. hardcopy, digital)
    char itemFormat;
    
    // The number of copies of an item
    int totalCopies;
    
    // The number of copies which are checked out
    int checkedOutCopies;
    
    // Static const variables which are used in print methods
    // to display information in the right format
    const static int
    YEAR_COL_WIDTH = 6,
    MONTH_COL_WIDTH = 5,
    TITLE_COL_WIDTH = 30,
    AUTHOR_COL_WIDTH = 15,
    AVAILABLE_COL_WIDTH = 6;
    
};

#endif /*ITEM_H*/
