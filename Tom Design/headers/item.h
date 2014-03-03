

//-----------------------------------------------------------------------------
// class Item
//
// Represents an individual item inside the library.
//
//-----------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H
#include "hashable.h"
#include "prototype.h"

class Item: Prototype : Hashable {
public:
	Item(); // Constructor
	~Item(); // Destructor
	virtual int compare(Item, Item) = 0; // compare
    virtual void print() = 0; // abstraction print function

    string getTitle(); // title accessor
    int getAmount(); // amount accessor
    User[] getCheckout(); // checkout accessor

    void setTitle(string t); // title mutator
    void setAmount(int a); // amount mutator
    void setCheckout(User[] c); // checkout mutator
private:
	String title; // title of the item
	int amount; // amount of items 
	User[] checkout; // the users the book is checked out to.
};

#endif