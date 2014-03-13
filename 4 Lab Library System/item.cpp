//-----------------------------------------------------------------------------
// ITEM.CPP
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
#include "item.h"

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Item class. Set the number of total copies to 5,
 the bumber of checkout copies to 0 and item formato to 'H' (hardcopy)
 ----------------------------------------------------------------------------*/
Item:: Item(){
    totalCopies = 5;
    checkedOutCopies = 0;
    itemFormat = 'H';
    cout.setf(ios::left, ios::adjustfield);
}

/*---------------------------------------------------------------------------
 ===== Destructor
 Descripton: Destructor for Item class.
 Pre:
 Post: deallocated.
 ----------------------------------------------------------------------------*/
Item:: ~Item(){
}

/*---------------------------------------------------------------------------
 ===== getItemType
 Descripton: Retrieve the item type
 Pre:
 Post: Returns the item type
 ----------------------------------------------------------------------------*/
char Item:: getItemType()const{
    return itemType;
}

/*---------------------------------------------------------------------------
 ===== setItemType
 Descripton: Set the item type
 ----------------------------------------------------------------------------*/
void Item:: setItemType(char type){
    itemType = type;
}

char Item::getItemFormat() const {
    return itemFormat;
}


/*---------------------------------------------------------------------------
 ===== getTotalCopies
 Descripton: Retrieve the total copies of item
 Pre:
 Post: Returns the total copies of item
 ----------------------------------------------------------------------------*/
int Item:: getTotalCopies() const{
    return totalCopies;
}

/*---------------------------------------------------------------------------
 ===== setTotalCopies
 Descripton: Set the total number of copies of item
 ----------------------------------------------------------------------------*/
void Item:: setTotalCopies(int newTotalCopies){
    totalCopies = newTotalCopies;
}

/*---------------------------------------------------------------------------
 ===== getCheckedOutCopies
 Descripton: Retrieve the number of copies checked out
 Pre:
 Post: Returns the number of copies checked out
 ----------------------------------------------------------------------------*/
int Item:: getCheckedOutCopies() const{
    return checkedOutCopies;
}

/*---------------------------------------------------------------------------
 ===== setCheckedOutCopies
 Descripton: Set the number of copies checked out
 ----------------------------------------------------------------------------*/
void Item:: setCheckedOutCopies(int newCheckOutCopies){
    checkedOutCopies = newCheckOutCopies;
}

/*---------------------------------------------------------------------------
 ===== getYear
 Descripton: Retrive the publication year of the item
 Pre:
 Post: Returns the publication year of the item
 ----------------------------------------------------------------------------*/
int Item:: getYear() const{
    return year;
}

/*---------------------------------------------------------------------------
 ===== setYear
 Descripton: Set the publication year
 ----------------------------------------------------------------------------*/
void Item:: setYear(int newYear){
    year = newYear;
}

/*---------------------------------------------------------------------------
 ===== getTitle
 Descripton: Retrive the title of the item
 Pre:
 Post: Returns the title of the item
 ----------------------------------------------------------------------------*/
string Item:: getTitle() const{
    return title;
}

/*---------------------------------------------------------------------------
 ===== setTitle
 Descripton: Set the title of the item
 ----------------------------------------------------------------------------*/
void Item:: setTitle(string newTitle){
    title = newTitle;
}

/*---------------------------------------------------------------------------
 ===== hash
 Descripton: Hash function
 Pre:
 Post: Return the item type
 ----------------------------------------------------------------------------*/
char Item:: hash()const{
    return itemType;
}



