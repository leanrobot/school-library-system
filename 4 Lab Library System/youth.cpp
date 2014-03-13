//-----------------------------------------------------------------------------
// YOUTH.CPP
// Youth class
// Authors: Magdalena Grzmiel and Thomas Petit
//-----------------------------------------------------------------------------
// Youth class: a class to represent the youth objetcs. It is a child class
// of Book class. Includes following features:
// -- Compare operators (==, !=, >, <)to compare two youths
// -- Create youth object
// -- Initialized the youth object
// -- Print the information about the youth object
// -- Print the header
// -- Print information about the youth object in user's history
// Assumptions:
// --Assumes correct and valid input from user for datamembers
//-----------------------------------------------------------------------------
#include "youth.h"
#include <iomanip>

/*---------------------------------------------------------------------------
 ===== Constructor
 Descripton: Constructor for Youth class.
 ----------------------------------------------------------------------------*/
Youth:: Youth(){
    itemType = 'Y';
}

/*---------------------------------------------------------------------------
 ===== operator<
 Descripton: Overloaded less than operator. Determine if this youth's object
 is less than the other youth's object.
 Pre:
 Post: Return true if this youth object is less than other youth object,
 false otherwise.
 ----------------------------------------------------------------------------*/
bool Youth:: operator<(const Item& item) const{
    if(item.getItemType() != itemType) return false;
    
    // cast the item object to the youth object
    const Youth& otherYouth = static_cast<const Youth&>(item);
    
    // first compare the titles, if this youth's title is less than other
    // youth's title, return true
    if (this->title.compare(otherYouth.title)<0){
        return true;
    }
    
    // if the titles are equal, compare the authors
    if (this->title.compare(otherYouth.title)==0){
        if (this->author.compare(otherYouth.author) < 0){
            return true;
        }
    }
    return false;
}

/*---------------------------------------------------------------------------
 ===== operator<
 Descripton: Overloaded greater than operator. Determine if this youth's
 object is greater than the other youth's object.
 Pre:
 Post: Return true if this youth object is greater than other youth object,
 false otherwise.
 ----------------------------------------------------------------------------*/
bool Youth:: operator>(const Item& item) const{
    return !(*this < item) && *this != item;
}

/*---------------------------------------------------------------------------
 ===== operator==
 Descripton: Overloaded equal operator. Determine if two youth objects are
 equal.
 Pre:
 Post: Return true if two youth objects are equal, false otherwise.
 ----------------------------------------------------------------------------*/
bool Youth:: operator== (const Item& item)const{
    if(item.getItemType() != itemType) return false;
    
    // cast the item object to the youth object
    const Youth& otherYouth = static_cast<const Youth&>(item);
    
    return ((this->title.compare(otherYouth.title) == 0) &&
            (this->author.compare(otherYouth.author) == 0));
}

/*---------------------------------------------------------------------------
 ===== operator!=
 Descripton: Overloaded not equal operator. Determine if two youth objects
 are not equal.
 Pre:
 Post: Return true if two periodicals are not equal, false otherwise
 ----------------------------------------------------------------------------*/
bool Youth:: operator!= (const Item& item)const{
    return !(*this == item);
}

/*---------------------------------------------------------------------------
 ===== create
 Descripton: Create youth object.
 Pre:
 Post: Return youth object
 ----------------------------------------------------------------------------*/
Item* Youth:: create(){
    Item* newYouthBook = new Youth;
    return newYouthBook;
}

/*---------------------------------------------------------------------------
 ===== initialize
 Descripton: Read the data from file and initialized the youth object
 when new youth object is added to the library
 Pre:
 Post:Return youth object
 ----------------------------------------------------------------------------*/
void Youth::initialize(istream& infile) {
    string author, title;
    
    getline(infile, author, ','); // input author, looks for comma terminator
    infile.get();                 // get (and ignore) blank before title
    getline(infile, title, ',');  // input title
    int year;
    infile >> year;               // input year
    infile.get();                 // discard new line character
    
    // set up the author, title and year
    this->setAuthor(author);
    this->setTitle(title);
    this->setYear(year);
}

/*---------------------------------------------------------------------------
 ===== initializePartial
 Descripton: Read the data from file and initialized the youth object
 to perform given transaction on it
 Pre:
 Post:Return youth object
 ----------------------------------------------------------------------------*/
void Youth::initializePartial(istream& infile) {
    string title, author;
    
    itemFormat = infile.get(); // set item format
    infile.get();		// discard trailing space.
    getline(infile, title, ',');   // input title, looks for comma terminator
    infile.get();
    getline(infile, author, ',');  // input author
    infile.get();                  // discard the newline
    
    // set up title and author
    this->setTitle(title);
    this->setAuthor(author);
}

/*----------------------------------------------------------------------------
 ===== print
 Descripton: Print information abou the youth object
 ----------------------------------------------------------------------------*/
void Youth:: print() const {
    cout <<
    " " << setw(AVAILABLE_COL_WIDTH) << (totalCopies - checkedOutCopies) <<
    " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) <<
    " " << setw(AUTHOR_COL_WIDTH) << author.substr(0, AUTHOR_COL_WIDTH) <<
    " " << setw(YEAR_COL_WIDTH) << year << endl;
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print header for the print method
 ----------------------------------------------------------------------------*/
void Youth:: printHeader()const {
    cout << "Youth:" << endl;
    cout <<
    setw(AVAILABLE_COL_WIDTH+2) << "AVAIL" <<
    setw(TITLE_COL_WIDTH+1) << "TITLE" <<
    setw(AUTHOR_COL_WIDTH+1) << "AUTHOR" <<
    setw(YEAR_COL_WIDTH+1) << "YEAR" << endl;
}

/*---------------------------------------------------------------------------
 ===== print
 Descripton: Print information about the youth objects which is used in the
 print method in the history transaction object
 ----------------------------------------------------------------------------*/
void Youth:: display()const {
    cout <<
    " " << setw(TITLE_COL_WIDTH) << title.substr(0, TITLE_COL_WIDTH) <<
    " " << setw(AUTHOR_COL_WIDTH) << author.substr(0, AUTHOR_COL_WIDTH) <<
    " " << setw(YEAR_COL_WIDTH) << year << endl;
}

