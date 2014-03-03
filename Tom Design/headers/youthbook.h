

//-----------------------------------------------------------------------------
// class YouthBook
//
// Represents a special sub class type of a book that contains only Youth
// specific attributes.
//
//-----------------------------------------------------------------------------

#ifndef YOUTHBOOK_H
#define YOUTHBOOK_H
#include "book.h"
#include <string>

class YouthBook : public Book {
public:
    YouthBook(string title, string author, int year);
    			// Constructor
    ~YouthBook();
    			// Destructor
    int compare(Item*);
    			// comparator.
};

#endif