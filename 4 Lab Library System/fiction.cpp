//-----------------------------------------------------------------------------
// FICTION.CPP
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
#include "fiction.h"
#include <iomanip>
#include <iostream>

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Fiction class.
----------------------------------------------------------------------------*/
Fiction:: Fiction(): Book(){
    itemType = 'F';
}

/*---------------------------------------------------------------------------
 ===== operator<
 Descripton: Overloaded less than operator. Determine if this fiction's 
 object is less than the other fiction's object.
 Pre:
 Post: Return true if this fiction object is less than other fiction object,
 false otherwise.
 ----------------------------------------------------------------------------*/
bool Fiction:: operator< (const Item& item)const{
    if(item.getItemType() != itemType) return false;
  
    // cast the item object to the fiction object
    const Fiction& otherFiction = static_cast<const Fiction&>(item);
    
    // first compare the authors
    if (this->author.compare(otherFiction.author) < 0){
        return true;
    }
    
    // if authors are the same, compare the titles
    if (this->author.compare(otherFiction.author) == 0){
        if (this->title.compare(otherFiction.title) < 0){
            return true;
        }
    }
    
    return false;
}

/*---------------------------------------------------------------------------
 ===== operator<
 Descripton: Overloaded greater than operator. Determine if this fiction's
 object is greater than the other fition's object.
 Pre:
 Post: Return true if this fiction object is greater than other fiction 
 object, false otherwise
 ----------------------------------------------------------------------------*/
bool Fiction:: operator> (const Item& item)const{
    return !(*this < item) && *this != item;
}

/*---------------------------------------------------------------------------
 ===== operator==
 Descripton: Overloaded equal operator. Determine if two fiction objects are
 equal.
 Pre:
 Post: Return true if two fiction objects are equal, false otherwise.
 ----------------------------------------------------------------------------*/
bool Fiction:: operator== (const Item& item)const{
    // cast the item object to the fiction object
    if(item.getItemType() != itemType) return false;
    
    const Fiction& otherFiction = static_cast<const Fiction&>(item);
    
    return ((this->author.compare(otherFiction.author)== 0) &&
            (this->title.compare(otherFiction.title) == 0));
}

/*---------------------------------------------------------------------------
 ===== operator!=
 Descripton: Overloaded not equal operator. Determine if two fiction objects
 are equal.
 Pre:
 Post: Return true if two fiction objects are not equal, false otherwise.
 ----------------------------------------------------------------------------*/
bool Fiction:: operator!= (const Item& item) const{
    return !(*this==item);
}

/*---------------------------------------------------------------------------
 ===== create
 Descripton: Create fiction object.
 Pre:
 Post: Return fiction object
 ----------------------------------------------------------------------------*/
Item* Fiction:: create(){
    return new Fiction();
}

/*---------------------------------------------------------------------------
 ===== initialize
 Descripton: Read the data from file and initialized the fiction object
 when new fiction object is added to the library
 Pre:
 Post:Return fiction object
 ----------------------------------------------------------------------------*/
void Fiction:: initialize(istream& infile){
    string author, title;
    int year;
    
    getline(infile, author, ',');  // input author, looks for comma terminator
    infile.get();                  // get (and ignore) blank before title
    getline(infile, title, ',');   // input title, looks for comma terminator
    infile >> year;                // input year
    infile.get();                  //discard new line character
    
    // set up uthor, title and year
    this->setAuthor(author);
    this -> setTitle(title);
    this->setYear(year);
}

/*---------------------------------------------------------------------------
 ===== initializePartial
 Descripton: Read the data from file and initialized the fiction object
 to perform given transaction on it
 Pre:
 Post:Return fiction object
 ----------------------------------------------------------------------------*/
void Fiction:: initializePartial(istream& infile){
    string author, title;
    
    itemFormat = infile.get();                
    infile.get();			 // discard space
    getline(infile, author, ','); // input author, looks for comma terminator
    infile.get();                 // get (and ignore) blank before title
    getline(infile, title, ',');  // input title
    infile.get();                 // discard the newline
    
    // set up author and title
    this->setAuthor(author);
    this->setTitle(title);
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print information abou the fiction object
 ----------------------------------------------------------------------------*/
void Fiction:: print()const {
    cout <<
    " " << setw(AVAILABLE_COL_WIDTH) << (totalCopies - checkedOutCopies) <<
    " " << setw(AUTHOR_COL_WIDTH) << author.substr(0, AUTHOR_COL_WIDTH) <<
    " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) <<
    " " << setw(YEAR_COL_WIDTH) << year << endl;
}
/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print header for the print method
 ----------------------------------------------------------------------------*/
void Fiction:: printHeader()const {
    cout << "Fiction:" << endl;
    cout <<
    setw(AVAILABLE_COL_WIDTH+2) << "AVAIL" <<
    setw(AUTHOR_COL_WIDTH+1) << "AUTHOR" <<
    setw(TITLE_COL_WIDTH+1) << "TITLE" <<
    setw(YEAR_COL_WIDTH+1) << "YEAR" << endl;
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print information about the fiction objects which is used in the
 print method in the history transaction object
 ----------------------------------------------------------------------------*/
void Fiction:: display()const {
    cout <<
    " " << setw(AUTHOR_COL_WIDTH) << author.substr(0, AUTHOR_COL_WIDTH) <<
    " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) <<
    " " << setw(YEAR_COL_WIDTH) << year << endl;
}
