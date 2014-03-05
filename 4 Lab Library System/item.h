//-----------------------------------------------------------------------
//item is an object that represents a generic item that can be checked out
//Includes:
//--records the number of copies of an item and the number checked out
//--Item is the parent class for book objects (and possibly others if added)
//Assumptions:
//--assumes correct and valid input of item data (total copies ect.)
//------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {

public:
	
	//destructor
	virtual ~Item();

    //retrieve the item type
    char getItemType() const;

    //manually set the itemtype
    void setItemType(char);

    //set the total number of copies of item
    void setTotalCopies(int);

    //retrieve the total copies of item
    int getTotalCopies() const;

    //set the number of copies checked out
    void setCheckedOutCopies(int);

    //retrieve number of copies checked out
    int getCheckedOutCopies() const;
    
    //retrieve the publication date of the media
    int getYear() const;
    
    //set the year with the int parameter
    void setYear(int);
    
    //retrieve the title
    string getTitle() const;
    
    //set the title to the string parameter
    void setTitle(string);

    //overloaded comparison operators
    virtual bool operator<(const Item &) const = 0;

    virtual bool operator==(const Item &) const = 0;
    
    //create an item
    virtual Item* create(istream&) = 0;
	
	//get description of an Item, like author, title, date
	//virtual string getDescription() const = 0;

    virtual void print()const = 0;

protected:
    
    //default constructor
    Item();
    
    Item (char, string, int);
    
    int year;
    
    string title;
    
    //designates what the item is (in this case 'i' for item)
    char itemType;
    
private:
    
     //format is the format of the item (i.e. hardcopy, digital)
    char itemFormat;

    //totalcopies keeps track of the number of copies of an item there are
    int totalCopies;

    //checkedoutcopies keeps track of how many of the copies are
    //checked out
    int checkedOutCopies;
    
};

#endif
