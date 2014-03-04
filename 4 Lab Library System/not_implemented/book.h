//----------------------------------------------------
//Book class: a class that defines a book object
//--Parent class of periodical and nonperiodical
//--Child class of item
//Includes:
//--creats book objects will all datamembers that are common to all books
//--comparison operators
//--get and set datamembers
//Assumptions:
//--Assumes that valid input is given for datamembers
//----------------------------------------------------

#ifndef BOOK_H
#define BOOK_H
#include "item.h"
#include <string>

class Book : public Item{

public:

    //default constructor
	Book();

    //constructor with parameters for title and year
    Book(string, int);

    //retrieve the title
    string getTitle() const;

    //set the title to the string parameter
    void setTitle(string);

    //retrieve the publication date of the media
    int getYear() const;

    //set the year with the int parameter
    void setYear(int);

    //overloaded comparison operators
    virtual bool operator<(const Item&) const;

    //create an item
    virtual Item* create();
	
	//get description of a book, like author, title, date
	virtual string getDescription() const = 0;

private:

    //contains title of book
    string title;

    //year of publication
    int year;

    //format is the format of the item (i.e. hardcopy, digital)
    char format;
};

#endif
