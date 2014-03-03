
//-----------------------------------------------------------------------------
// class Book
//
// Represents a item inside the library of type book.
//
//-----------------------------------------------------------------------------

#ifndef "__BOOK_H"
#define "__BOOK_H"

#include "item.h"

class Book : public Item {
public:
	Book(string title, string author, int year); // Constructor
	~Book(); // Destructor
private:
	virtual int compare(const Item* i) const = 0;// Abstract comparison function
};

#endif