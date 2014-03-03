

//-----------------------------------------------------------------------------
// class FictionBook
//
// Sub class of Book that contains information about fiction books specifically.
//
//-----------------------------------------------------------------------------

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H
#include "book.h"
#include <string>

class FictionBook : public Book {
public:
    FictionBook(string author, string title, int year); // Constructor
    ~FictionBook();		// Destructor
    int compare(Item*); // Comparison 
};

#endif